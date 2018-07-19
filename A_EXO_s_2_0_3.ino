// This is the code for the Single board Ankle Exoskeleton -> A_EXO_s
//
// FSR sensors retrieve the sensor voltage related to the foot pressure. 
// The state machine (Left and Right state machine) identify the participant status depending on the voltage.
// The torque reference is decided by the user (Matlab GUI) and send as reference to the PID control.
// The PID control and data tranmission to the GUI are scheduled by an interrupt.
// 
// Sensor can be calibrated by the user and/or saved calibration can be loaded to speed up the setup.
// 
// The torque reference can be smoothed by sigmoid functions
// In case of too long steady state the torque reference is set to zero
// In case of new torque reference the torque amount is provided gradually as function of the steps.
//
// Ex: Torque ref = 10N
// 1 step = 0N
// 2 steps = 2N
// 3 steps = 4N
// 4 steps = 6N
// 5 steps = 8N
// 6 steps = 10N
// 
// The torque and the shaping function can be adapted as function of the force pressure/Voltage 
// and averaged speed/step duration
//
// Several parameters can be modified thanks to the Receive and Transmit functions


#include <elapsedMillis.h>
#include <EEPROM.h>
#include "TimerOne.h"
#include <PID_v2.h>
#include <SoftwareSerial.h>
#include "Torque_Speed_ADJ.h"
#include "Memory_address.h"
#include "Shaping_Parameters.h"
#include "FSR_Parameters.h"
#include "PID_and_Ctrl_Parameters.h"
#include "Filter_Parameters.h"
#include "State_Machine_Parameters.h"
#include "Reference_ADJ.h"


//To interrupt and to schedule we take advantage of the 
elapsedMillis timeElapsed;
double startTime = 0;
int streamTimerCount = 0;

int stream = 0;

char holdon[24];
char *holdOnPoint = &holdon[0];
char Peek = 'a';
int garbage = 0;

const unsigned int onoff = 2;                                          //The digital pin connected to the motor on/off swich
const unsigned int zero = 1540;                                       //whatever the zero value is for the PID analogwrite setup
const unsigned int which_leg_pin = 15;


//Includes the SoftwareSerial library to be able to use the bluetooth Serial Communication
int bluetoothTx = 0;                                                 // TX-O pin of bluetooth mate, Teensy D0
int bluetoothRx = 1;                                                 // RX-I pin of bluetooth mate, Teensy D1
SoftwareSerial bluetooth(bluetoothTx, bluetoothRx);                  // Sets an object named bluetooth to act as a serial port


void setup()
{
  // set the interrupt
  Timer1.initialize(2000);         // initialize timer1, and set a 10 ms period *note this is 10k microseconds*
  Timer1.pwm(9, 512);                // setup pwm on pin 9, 50% duty cycle
  Timer1.attachInterrupt(callback);  // attaches callback() as a timer overflow interrupt

  // enable bluetooth
  bluetooth.begin(115200);
  Serial.begin(115200);
  //while (!Serial) {};

  analogWriteResolution(12);                                          //change resolution to 12 bits
  analogReadResolution(12);                                           //ditto

  // The led
  pinMode(13, OUTPUT);
  digitalWrite(13, HIGH);
  // set pin mode for left and right sides
  pinMode(22, OUTPUT); //Enable disable the motors
  digitalWrite(22, LOW);

  pinMode(A19, INPUT); //enable the torque reading of the left torque sensor
  pinMode(A18, INPUT); //enable the torque reading of the right torque sensor

  //change the origin of the motor
  analogWrite(motor_LL_pin, zero);
  analogWrite(motor_RL_pin, zero);

  //  Left PID
  PID_LL.SetMode(AUTOMATIC);
  PID_LL.SetTunings(kp_LL, ki_LL, kd_LL);                                      //Kp, Ki, Kd ##COULD BE AUTOTUNED
  PID_LL.SetOutputLimits(-1500, 1500);                                  //range of Output around 0 ~ 1995 ##THIS IS DIFFERENT NOW AND SHOULD CONCRETELY CONFIRM
  PID_LL.SetSampleTime(PID_sample_time);                              //what is the sample time we want in millis

  //  Right PID
  PID_RL.SetMode(AUTOMATIC);
  PID_RL.SetTunings(kp_RL, ki_RL, kd_RL);                                      //Kp, Ki, Kd ##COULD BE AUTOTUNED
  PID_RL.SetOutputLimits(-1500, 1500);                                  //range of Output around 0 ~ 1995 ##THIS IS DIFFERENT NOW AND SHOULD CONCRETELY CONFIRM
  PID_RL.SetSampleTime(PID_sample_time);                              //what is the sample time we want in millis

  // Fast torque calibration
  torque_calibration();

}




void callback()
{

  if (stream == 1)
  {
    set_2_zero_if_steady_state();

    //    Serial.println("LEFT");
    N3_LL = Torque_ADJ(L_state, L_state_old, L_p_steps, N3_LL, New_PID_Setpoint_LL, p_Setpoint_Ankle_LL);
    //    Serial.println("RIGHT");
    N3_RL = Torque_ADJ(R_state, R_state_old, R_p_steps, N3_RL, New_PID_Setpoint_RL, p_Setpoint_Ankle_RL);

    if (streamTimerCount == 5)
    {
      bluetooth.println(Average_RL);
      bluetooth.println(R_state);
      bluetooth.println(PID_Setpoint_RL);         //Right Setpoint
      bluetooth.println(fsr(fsr_sense_Right_Toe));         //Right Voltage/Voltage of FSR
      bluetooth.println(Average_LL);
      bluetooth.println(L_state);
      bluetooth.println(PID_Setpoint_LL);         //Left 9
      bluetooth.println(fsr(fsr_sense_Left_Toe));         //Left Voltage/Voltage of FSR
      streamTimerCount = 0;

      //Update Current voltage
      L_p_steps->curr_voltage = fsr(fsr_sense_Left_Toe);
      R_p_steps->curr_voltage = fsr(fsr_sense_Right_Toe);
    }
    streamTimerCount++;

    //Calc the average value of Torque

    //Shift the arrays
    for (int j = dim; j >= 0; j--)                    //Sets up the loop to loop the number of spaces in the memory space minus 2, since we are moving all the elements except for 1
    { // there are the number of spaces in the memory space minus 2 actions that need to be taken
      *(TarrayPoint_LL + j) = *(TarrayPoint_LL + j - 1);                //Puts the element in the following memory space into the current memory space
      *(TarrayPoint_RL + j) = *(TarrayPoint_RL + j - 1);
    }

    //Get the torques
    T_act_LL = get_LL_torq();
    T_act_RL = get_RL_torq();
    *(TarrayPoint_LL) = T_act_LL;
    *(TarrayPoint_RL) = T_act_RL;

    Average_LL = 0;
    Average_RL = 0;
    for (int i = 0; i < dim; i++)
    {
      Average_LL = Average_LL + *(TarrayPoint_LL + i);
      Average_RL = Average_RL + *(TarrayPoint_RL + i);
    }
    Average_LL = Average_LL / dim;
    Average_RL = Average_RL / dim;

    //Apply PID control
    pid(Average_LL, 1);
    pid(Average_RL, 2);
  }
}


void loop()
{

  while (bluetooth.available() == 0)
  {
    if (stream == 1)
    {
      state_machine_LL();  //for LL
      state_machine_RL();  //for RL
    }
    else
    {

      //Reset the starting values
      L_p_steps->count_steps = 0;
      L_p_steps->n_steps = 0;
      L_p_steps->flag_1_step = false;
      L_p_steps->flag_take_average = false;
      L_p_steps->flag_N3_adjustment_time = false;
      L_p_steps->flag_take_baseline = false;
      L_p_steps->torque_adj = false;

      R_p_steps->count_steps = 0;
      R_p_steps->n_steps = 0;
      R_p_steps->flag_1_step = false;
      R_p_steps->flag_take_average = false;
      R_p_steps->flag_N3_adjustment_time = false;
      R_p_steps->flag_take_baseline = false;
      R_p_steps->torque_adj = false;

      N3_LL = N3;
      N2_LL = N2;
      N1_LL = N1;

      N3_RL = N3;
      N2_RL = N2;
      N1_RL = N1;

      L_p_steps->perc_l = 0.5;
      R_p_steps->perc_l = 0.5;

      L_activate_in_3_steps = 1;
      R_activate_in_3_steps = 1;

    }
  }

  receive_and_transmit();
}
