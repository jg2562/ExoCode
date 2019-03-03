#include "Leg.h"
//void state_machine(Leg* leg)
//{
//
//
//  if (FLAG_TWO_TOE_SENSORS) {
//
//    switch (leg->state)
//    {
//      case 1: //Swing
//        // This flag enables the "set to zero" procedure for the left ankle.
//        // When you're for at least 3 seconds in the same state, the torque reference is set to zero
//
//        if (leg->set_2_zero == 1) {
//          leg->set_2_zero = 0;
//          leg->One_time_set_2_zero = 1;
//        }
//        else if ((leg->p_steps->curr_voltage > leg->fsr_percent_thresh_Toe * leg->fsr_Combined_peak_ref))
//        {
//          leg->state_count_13++;
//          // if you're in the same state for more than state_counter_th it means that it is not noise
//          if (leg->state_count_13 >= state_counter_th)
//          {
//            leg->sigm_done = true;
//            leg->Old_PID_Setpoint = leg->PID_Setpoint;
//
//            if (abs(leg->Dorsi_Setpoint_Ankle) > 0) {
//              //            //            leg->Previous_Setpoint_Ankle = 0;
//              leg->Old_PID_Setpoint = 0;
//              //            leg->Setpoint_Ankle = 0;
//            } else {
//              leg->Previous_Dorsi_Setpoint_Ankle = 0;
//            }
//
//            if (leg->Previous_Setpoint_Ankle <= leg->Setpoint_Ankle) {
//
//              leg->New_PID_Setpoint = leg->Previous_Setpoint_Ankle + (leg->Setpoint_Ankle - leg->Previous_Setpoint_Ankle) * leg->coef_in_3_steps;
//
//            } else {
//
//              leg->New_PID_Setpoint = leg->Previous_Setpoint_Ankle - (leg->Previous_Setpoint_Ankle - leg->Setpoint_Ankle) * leg->coef_in_3_steps;
//
//            }
//
//            leg->state_old = leg->state;
//            leg->state = 3;
//            leg->state_count_13 = 0;
//            leg->state_count_31 = 0;
//          }
//        }
//
//        break;
//      case 3: //Late Stance
//
//
//        //      leg->N3 = leg->old_N3;
//        //      leg->N2 = leg->old_N2;
//        //      leg->N1 = leg->old_N1;
//
//
//        if ((leg->set_2_zero == 1) && (leg->One_time_set_2_zero)) {
//          leg->sigm_done = true;
//          leg->Old_PID_Setpoint = leg->PID_Setpoint;
//          leg->state_old = leg->state;
//          leg->New_PID_Setpoint = 0;
//          leg->One_time_set_2_zero = 0;
//          leg->Previous_Setpoint_Ankle = 0;
//          leg->PID_Setpoint = 0;
//          leg->Setpoint_Ankle_Pctrl = 0;
//        }
//
//        if ((leg->p_steps->curr_voltage < (leg->fsr_percent_thresh_Toe * leg->fsr_Combined_peak_ref)))
//        {
//          leg->state_count_31++;
//          if (leg->state_count_31 >= state_counter_th)
//          {
//            leg->sigm_done = true;
//            leg->Old_PID_Setpoint = leg->PID_Setpoint;
//            leg->state_old = leg->state;
//            //          leg->New_PID_Setpoint = 0 * leg->coef_in_3_steps;
//
//
//            if (leg->Previous_Dorsi_Setpoint_Ankle <= leg->Dorsi_Setpoint_Ankle) {
//
//              leg->New_PID_Setpoint = leg->Previous_Dorsi_Setpoint_Ankle + (leg->Dorsi_Setpoint_Ankle - leg->Previous_Dorsi_Setpoint_Ankle) * leg->coef_in_3_steps;
//
//            } else {
//
//              leg->New_PID_Setpoint = leg->Previous_Dorsi_Setpoint_Ankle - (leg->Previous_Dorsi_Setpoint_Ankle - leg->Dorsi_Setpoint_Ankle) * leg->coef_in_3_steps;
//
//            }
//
//            leg->state = 1;
//            leg->state_count_31 = 0;
//            leg->state_count_13 = 0;
//          }
//        }
//    }
//    // Adjust the torque reference as a function of the step
//    ref_step_adj(leg);
//
//    if ((Control_Mode == 2 || Control_Mode == 3) && leg->state == 3) {
//      leg->PID_Setpoint = leg->Setpoint_Ankle_Pctrl;
//      //    Serial.println("After switch case : ");
//      //    Serial.println(leg->coef_in_3_steps_Pctrl);
//      //    Serial.println(leg->Setpoint_Ankle_Pctrl);
//      //    Serial.println(leg->PID_Setpoint);
//      //    Serial.println();
//    }
//    else {
//
//      if (N1 < 1 || N2 < 1 || N3 < 1) {
//        leg->PID_Setpoint = leg->New_PID_Setpoint;
//      }
//      else {
//        // Create the smoothed reference and call the PID
//        PID_Sigm_Curve(leg);
//      }
//
//    }
//  }//end if (FLAG_TWO_TOE_SENSORS)
//  else {
//    // in case we do not do balance but we want to use two sensors one on the heel one on the toe
//
//    switch (leg->state)
//    {
//      case 1: //Swing
//        // This flag enables the "set to zero" procedure for the left ankle.
//        // When you're for at least 3 seconds in the same state, the torque reference is set to zero
//
//        if (leg->set_2_zero == 1) {
//          leg->set_2_zero = 0;
//          leg->One_time_set_2_zero = 1;
//        }
//        else if ((leg->p_steps->curr_voltage > leg->fsr_percent_thresh_Toe * leg->fsr_Toe_peak_ref))
//        {
//          leg->state_count_13++;
//          // if you're in the same state for more than state_counter_th it means that it is not noise
//          if (leg->state_count_13 >= state_counter_th)
//          {
//            leg->sigm_done = true;
//            leg->Old_PID_Setpoint = leg->PID_Setpoint;
//
//            if (abs(leg->Dorsi_Setpoint_Ankle) > 0) {
//              //            //            leg->Previous_Setpoint_Ankle = 0;
//              leg->Old_PID_Setpoint = 0;
//              //            leg->Setpoint_Ankle = 0;
//            } else {
//              leg->Previous_Dorsi_Setpoint_Ankle = 0;
//            }
//
//            if (leg->Previous_Setpoint_Ankle <= leg->Setpoint_Ankle) {
//
//              leg->New_PID_Setpoint = leg->Previous_Setpoint_Ankle + (leg->Setpoint_Ankle - leg->Previous_Setpoint_Ankle) * leg->coef_in_3_steps;
//
//            } else {
//
//              leg->New_PID_Setpoint = leg->Previous_Setpoint_Ankle - (leg->Previous_Setpoint_Ankle - leg->Setpoint_Ankle) * leg->coef_in_3_steps;
//
//            }
//
//            leg->state_old = leg->state;
//            leg->state = 3;
//            leg->state_count_13 = 0;
//            leg->state_count_31 = 0;
//          }
//        }
//
//        break;
//      case 3: //Late Stance
//
//
//        //      leg->N3 = leg->old_N3;
//        //      leg->N2 = leg->old_N2;
//        //      leg->N1 = leg->old_N1;
//
//
//        if ((leg->set_2_zero == 1) && (leg->One_time_set_2_zero)) {
//          leg->sigm_done = true;
//          leg->Old_PID_Setpoint = leg->PID_Setpoint;
//          leg->state_old = leg->state;
//          leg->New_PID_Setpoint = 0;
//          leg->One_time_set_2_zero = 0;
//          leg->Previous_Setpoint_Ankle = 0;
//          leg->PID_Setpoint = 0;
//          leg->Setpoint_Ankle_Pctrl = 0;
//        }
//
//        if ((leg->p_steps->curr_voltage < (leg->fsr_percent_thresh_Toe * leg->fsr_Toe_peak_ref)))
//        {
//          leg->state_count_31++;
//          if (leg->state_count_31 >= state_counter_th)
//          {
//            leg->sigm_done = true;
//            leg->Old_PID_Setpoint = leg->PID_Setpoint;
//            leg->state_old = leg->state;
//            //          leg->New_PID_Setpoint = 0 * leg->coef_in_3_steps;
//
//
//            if (leg->Previous_Dorsi_Setpoint_Ankle <= leg->Dorsi_Setpoint_Ankle) {
//
//              leg->New_PID_Setpoint = leg->Previous_Dorsi_Setpoint_Ankle + (leg->Dorsi_Setpoint_Ankle - leg->Previous_Dorsi_Setpoint_Ankle) * leg->coef_in_3_steps;
//
//            } else {
//
//              leg->New_PID_Setpoint = leg->Previous_Dorsi_Setpoint_Ankle - (leg->Previous_Dorsi_Setpoint_Ankle - leg->Dorsi_Setpoint_Ankle) * leg->coef_in_3_steps;
//
//            }
//
//            leg->state = 1;
//            leg->state_count_31 = 0;
//            leg->state_count_13 = 0;
//          }
//        }
//    }
//    // Adjust the torque reference as a function of the step
//    ref_step_adj(leg);
//
//    if ((Control_Mode == 2 || Control_Mode == 3) && leg->state == 3) {
//      leg->PID_Setpoint = leg->Setpoint_Ankle_Pctrl;
//      //    Serial.println("After switch case : ");
//      //    Serial.println(leg->coef_in_3_steps_Pctrl);
//      //    Serial.println(leg->Setpoint_Ankle_Pctrl);
//      //    Serial.println(leg->PID_Setpoint);
//      //    Serial.println();
//    }
//    else {
//
//      if (N1 < 1 || N2 < 1 || N3 < 1) {
//        leg->PID_Setpoint = leg->New_PID_Setpoint;
//      }
//      else {
//        // Create the smoothed reference and call the PID
//        PID_Sigm_Curve(leg);
//      }
//
//    }
//
//
//  }// end else , i.e. state machine with toe and heel sensors
//}// end state machine
//

//--------------------NEW FUNCTIONS-----------------
// Before state 3 in case of balance control was activated just in case of not negligible value 
// of the force on the toe i.e. if you just walk on the heel you never feel the balance.
// Right now the state 3 is activate also in case of heel contact and the state 1 is activated
// in case of no contact of both the sensors
void state_machine(Leg* leg)
{
  if (FLAG_TWO_TOE_SENSORS) {
    State_Machine_Two_Toe_Sensors(leg);
  } else {
    if (FLAG_BALANCE) {
      State_Machine_Heel_Toe_Sensors_Balance(leg);
    } else {
      State_Machine_Heel_Toe_Sensors(leg);
    }
  }
}




//-----------------------------------------------------------------------------------------------------
void State_Machine_Two_Toe_Sensors(Leg* leg) {
  switch (leg->state)
  {
    case 1: //Swing
      // This flag enables the "set to zero" procedure for the left ankle.
      // When you're for at least 3 seconds in the same state, the torque reference is set to zero

      if (leg->set_2_zero == 1) {
        leg->set_2_zero = 0;
        leg->One_time_set_2_zero = 1;
      }
      else if ((leg->p_steps->curr_voltage > leg->fsr_percent_thresh_Toe * leg->fsr_Combined_peak_ref))
      {
        leg->state_count_13++;
        // if you're in the same state for more than state_counter_th it means that it is not noise
        if (leg->state_count_13 >= state_counter_th)
        {
          leg->sigm_done = true;
          leg->Old_PID_Setpoint = leg->PID_Setpoint;

          if (abs(leg->Dorsi_Setpoint_Ankle) > 0) {
            //            //            leg->Previous_Setpoint_Ankle = 0;
            leg->Old_PID_Setpoint = 0;
            //            leg->Setpoint_Ankle = 0;
          } else {
            leg->Previous_Dorsi_Setpoint_Ankle = 0;
          }

          if (leg->Previous_Setpoint_Ankle <= leg->Setpoint_Ankle) {

            leg->New_PID_Setpoint = leg->Previous_Setpoint_Ankle + (leg->Setpoint_Ankle - leg->Previous_Setpoint_Ankle) * leg->coef_in_3_steps;

          } else {

            leg->New_PID_Setpoint = leg->Previous_Setpoint_Ankle - (leg->Previous_Setpoint_Ankle - leg->Setpoint_Ankle) * leg->coef_in_3_steps;

          }

          leg->state_old = leg->state;
          leg->state = 3;
          leg->state_count_13 = 0;
          leg->state_count_31 = 0;
        }
      }

      break;
    case 3: //Late Stance


      //      leg->N3 = leg->old_N3;
      //      leg->N2 = leg->old_N2;
      //      leg->N1 = leg->old_N1;


      if ((leg->set_2_zero == 1) && (leg->One_time_set_2_zero)) {
        leg->sigm_done = true;
        leg->Old_PID_Setpoint = leg->PID_Setpoint;
        leg->state_old = leg->state;
        leg->New_PID_Setpoint = 0;
        leg->One_time_set_2_zero = 0;
        leg->Previous_Setpoint_Ankle = 0;
        leg->PID_Setpoint = 0;
        leg->Setpoint_Ankle_Pctrl = 0;
      }

      if ((leg->p_steps->curr_voltage < (leg->fsr_percent_thresh_Toe * leg->fsr_Combined_peak_ref)))
      {
        leg->state_count_31++;
        if (leg->state_count_31 >= state_counter_th)
        {
          leg->sigm_done = true;
          leg->Old_PID_Setpoint = leg->PID_Setpoint;
          leg->state_old = leg->state;
          //          leg->New_PID_Setpoint = 0 * leg->coef_in_3_steps;


          if (leg->Previous_Dorsi_Setpoint_Ankle <= leg->Dorsi_Setpoint_Ankle) {

            leg->New_PID_Setpoint = leg->Previous_Dorsi_Setpoint_Ankle + (leg->Dorsi_Setpoint_Ankle - leg->Previous_Dorsi_Setpoint_Ankle) * leg->coef_in_3_steps;

          } else {

            leg->New_PID_Setpoint = leg->Previous_Dorsi_Setpoint_Ankle - (leg->Previous_Dorsi_Setpoint_Ankle - leg->Dorsi_Setpoint_Ankle) * leg->coef_in_3_steps;

          }

          leg->state = 1;
          leg->state_count_31 = 0;
          leg->state_count_13 = 0;
        }
      }
  }//end switch
  // Adjust the torque reference as a function of the step
  ref_step_adj(leg);

  if ((Control_Mode == 2 || Control_Mode == 3) && leg->state == 3) {
    leg->PID_Setpoint = leg->Setpoint_Ankle_Pctrl;
    //    Serial.println("After switch case : ");
    //    Serial.println(leg->coef_in_3_steps_Pctrl);
    //    Serial.println(leg->Setpoint_Ankle_Pctrl);
    //    Serial.println(leg->PID_Setpoint);
    //    Serial.println();
  }
  else {

    if (N1 < 1 || N2 < 1 || N3 < 1) {
      leg->PID_Setpoint = leg->New_PID_Setpoint;
    }
    else {
      // Create the smoothed reference and call the PID
      PID_Sigm_Curve(leg);
    }

  }


}// end function


void State_Machine_Heel_Toe_Sensors(Leg* leg) {

  switch (leg->state)
  {
    case 1: //Swing
      // This flag enables the "set to zero" procedure for the left ankle.
      // When you're for at least 3 seconds in the same state, the torque reference is set to zero

      if (leg->set_2_zero == 1) {
        leg->set_2_zero = 0;
        leg->One_time_set_2_zero = 1;
      }
      else if ((leg->p_steps->curr_voltage > leg->fsr_percent_thresh_Toe * leg->fsr_Toe_peak_ref))
      {
        leg->state_count_13++;
        // if you're in the same state for more than state_counter_th it means that it is not noise
        if (leg->state_count_13 >= state_counter_th)
        {
          leg->sigm_done = true;
          leg->Old_PID_Setpoint = leg->PID_Setpoint;

          if (abs(leg->Dorsi_Setpoint_Ankle) > 0) {
            //            //            leg->Previous_Setpoint_Ankle = 0;
            leg->Old_PID_Setpoint = 0;
            //            leg->Setpoint_Ankle = 0;
          } else {
            leg->Previous_Dorsi_Setpoint_Ankle = 0;
          }

          if (leg->Previous_Setpoint_Ankle <= leg->Setpoint_Ankle) {

            leg->New_PID_Setpoint = leg->Previous_Setpoint_Ankle + (leg->Setpoint_Ankle - leg->Previous_Setpoint_Ankle) * leg->coef_in_3_steps;

          } else {

            leg->New_PID_Setpoint = leg->Previous_Setpoint_Ankle - (leg->Previous_Setpoint_Ankle - leg->Setpoint_Ankle) * leg->coef_in_3_steps;

          }

          leg->state_old = leg->state;
          leg->state = 3;
          leg->state_count_13 = 0;
          leg->state_count_31 = 0;
        }
      }

      break;
    case 3: //Late Stance


      //      leg->N3 = leg->old_N3;
      //      leg->N2 = leg->old_N2;
      //      leg->N1 = leg->old_N1;


      if ((leg->set_2_zero == 1) && (leg->One_time_set_2_zero)) {
        leg->sigm_done = true;
        leg->Old_PID_Setpoint = leg->PID_Setpoint;
        leg->state_old = leg->state;
        leg->New_PID_Setpoint = 0;
        leg->One_time_set_2_zero = 0;
        leg->Previous_Setpoint_Ankle = 0;
        leg->PID_Setpoint = 0;
        leg->Setpoint_Ankle_Pctrl = 0;
      }

      if ((leg->p_steps->curr_voltage < (leg->fsr_percent_thresh_Toe * leg->fsr_Toe_peak_ref)))
      {
        leg->state_count_31++;
        if (leg->state_count_31 >= state_counter_th)
        {
          leg->sigm_done = true;
          leg->Old_PID_Setpoint = leg->PID_Setpoint;
          leg->state_old = leg->state;
          //          leg->New_PID_Setpoint = 0 * leg->coef_in_3_steps;


          if (leg->Previous_Dorsi_Setpoint_Ankle <= leg->Dorsi_Setpoint_Ankle) {

            leg->New_PID_Setpoint = leg->Previous_Dorsi_Setpoint_Ankle + (leg->Dorsi_Setpoint_Ankle - leg->Previous_Dorsi_Setpoint_Ankle) * leg->coef_in_3_steps;

          } else {

            leg->New_PID_Setpoint = leg->Previous_Dorsi_Setpoint_Ankle - (leg->Previous_Dorsi_Setpoint_Ankle - leg->Dorsi_Setpoint_Ankle) * leg->coef_in_3_steps;

          }

          leg->state = 1;
          leg->state_count_31 = 0;
          leg->state_count_13 = 0;
        }
      }
  }// end switch
  // Adjust the torque reference as a function of the step
  ref_step_adj(leg);

  if ((Control_Mode == 2 || Control_Mode == 3) && leg->state == 3) {
    leg->PID_Setpoint = leg->Setpoint_Ankle_Pctrl;
    //    Serial.println("After switch case : ");
    //    Serial.println(leg->coef_in_3_steps_Pctrl);
    //    Serial.println(leg->Setpoint_Ankle_Pctrl);
    //    Serial.println(leg->PID_Setpoint);
    //    Serial.println();
  }
  else {

    if (N1 < 1 || N2 < 1 || N3 < 1) {
      leg->PID_Setpoint = leg->New_PID_Setpoint;
    }
    else {
      // Create the smoothed reference and call the PID
      PID_Sigm_Curve(leg);
    }

  }
}// end function


//--------------------------------------------------------------------------------------------------
//    Serial.println(left_leg->FSR_Toe_Balance_Baseline);
//    Serial.println(left_leg->FSR_Heel_Balance_Baseline);
//    Serial.println(right_leg->FSR_Toe_Balance_Baseline);
//    Serial.println(right_leg->FSR_Heel_Balance_Baseline);



//leg->FSR_Toe_Average / leg->FSR_Toe_Balance_Baseline)) - min(1,(leg->FSR_Heel_Average

void State_Machine_Heel_Toe_Sensors_Balance(Leg* leg) {
  switch (leg->state)
  {
    case 1: //Swing
      // This flag enables the "set to zero" procedure for the left ankle.
      // When you're for at least 3 seconds in the same state, the torque reference is set to zero

      if (leg->set_2_zero == 1) {
        leg->set_2_zero = 0;
        leg->One_time_set_2_zero = 1;
      }
      //      else if ((leg->p_steps->curr_voltage > leg->fsr_percent_thresh_Toe * leg->fsr_Toe_peak_ref))
      else if ((leg->FSR_Toe_Average > leg->fsr_percent_thresh_Toe * leg->FSR_Toe_Balance_Baseline) || (leg->FSR_Heel_Average > leg->fsr_percent_thresh_Toe * leg->FSR_Heel_Balance_Baseline))
      {
        leg->state_count_13++;
        // if you're in the same state for more than state_counter_th it means that it is not noise
        if (leg->state_count_13 >= state_counter_th)
        {
          leg->sigm_done = true;
          leg->Old_PID_Setpoint = leg->PID_Setpoint;

          if (abs(leg->Dorsi_Setpoint_Ankle) > 0) {
            //            //            leg->Previous_Setpoint_Ankle = 0;
            leg->Old_PID_Setpoint = 0;
            //            leg->Setpoint_Ankle = 0;
          } else {
            leg->Previous_Dorsi_Setpoint_Ankle = 0;
          }

          if (leg->Previous_Setpoint_Ankle <= leg->Setpoint_Ankle) {

            leg->New_PID_Setpoint = leg->Previous_Setpoint_Ankle + (leg->Setpoint_Ankle - leg->Previous_Setpoint_Ankle) * leg->coef_in_3_steps;

          } else {

            leg->New_PID_Setpoint = leg->Previous_Setpoint_Ankle - (leg->Previous_Setpoint_Ankle - leg->Setpoint_Ankle) * leg->coef_in_3_steps;

          }

          leg->state_old = leg->state;
          leg->state = 3;
          leg->state_count_13 = 0;
          leg->state_count_31 = 0;
        }
      }

      break;
    case 3: //Late Stance


      //      leg->N3 = leg->old_N3;
      //      leg->N2 = leg->old_N2;
      //      leg->N1 = leg->old_N1;


      if ((leg->set_2_zero == 1) && (leg->One_time_set_2_zero)) {
        leg->sigm_done = true;
        leg->Old_PID_Setpoint = leg->PID_Setpoint;
        leg->state_old = leg->state;
        leg->New_PID_Setpoint = 0;
        leg->One_time_set_2_zero = 0;
        leg->Previous_Setpoint_Ankle = 0;
        leg->PID_Setpoint = 0;
        leg->Setpoint_Ankle_Pctrl = 0;
      }

      //      if ((leg->p_steps->curr_voltage < (leg->fsr_percent_thresh_Toe * leg->fsr_Toe_peak_ref)))
      if ((leg->FSR_Toe_Average < leg->fsr_percent_thresh_Toe * leg->FSR_Toe_Balance_Baseline) && (leg->FSR_Heel_Average < leg->fsr_percent_thresh_Toe * leg->FSR_Heel_Balance_Baseline))
      {
        leg->state_count_31++;
        if (leg->state_count_31 >= state_counter_th)
        {
          leg->sigm_done = true;
          leg->Old_PID_Setpoint = leg->PID_Setpoint;
          leg->state_old = leg->state;
          //          leg->New_PID_Setpoint = 0 * leg->coef_in_3_steps;


          if (leg->Previous_Dorsi_Setpoint_Ankle <= leg->Dorsi_Setpoint_Ankle) {

            leg->New_PID_Setpoint = leg->Previous_Dorsi_Setpoint_Ankle + (leg->Dorsi_Setpoint_Ankle - leg->Previous_Dorsi_Setpoint_Ankle) * leg->coef_in_3_steps;

          } else {

            leg->New_PID_Setpoint = leg->Previous_Dorsi_Setpoint_Ankle - (leg->Previous_Dorsi_Setpoint_Ankle - leg->Dorsi_Setpoint_Ankle) * leg->coef_in_3_steps;

          }

          leg->state = 1;
          leg->state_count_31 = 0;
          leg->state_count_13 = 0;
        }
      }
  }// end switch
  // Adjust the torque reference as a function of the step
  ref_step_adj(leg);

  if ((Control_Mode == 2 || Control_Mode == 3) && leg->state == 3) {
    leg->PID_Setpoint = leg->Setpoint_Ankle_Pctrl;
    //    Serial.println("After switch case : ");
    //    Serial.println(leg->coef_in_3_steps_Pctrl);
    //    Serial.println(leg->Setpoint_Ankle_Pctrl);
    //    Serial.println(leg->PID_Setpoint);
    //    Serial.println();
  }
  else {

    if (N1 < 1 || N2 < 1 || N3 < 1) {
      leg->PID_Setpoint = leg->New_PID_Setpoint;
    }
    else {
      // Create the smoothed reference and call the PID
      PID_Sigm_Curve(leg);
    }

  }

}// end function