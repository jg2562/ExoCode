// Stuctur in order to have all the needed values to adjust the torque or the shaping as a function of the force applied or of the speed respectively


typedef struct {
  int    n_steps;
  int    n_kf;
  int n_cycles;
  int prev_state;
  double dorsi_time;
  double plant_time;
  double dorsi_time_average;
  double four_step_dorsi_time[4];
  double four_step_plant_time[4];
  bool flag_take_average = false;
  bool flag_N3_adjustment_time = false;
  double dorsi_mean;
  double plant_mean;
  double dorsi_mean_old;
  double plant_mean_old;
  int count_steps;
  double torque_val;
  double torque_val_average;
  bool flag_1_step = false;
  bool flag_take_baseline = false;
  bool torque_adj = false;
  double Setpoint;
  double plant_mean_base;
  double dorsi_mean_base;
  double voltage_ref;
  double curr_voltage;
  double perc_l = 0.5;
  double fsr_percent_thresh_Toe=0.9;
  double plant_peak_mean;
  double four_step_plant_peak[4];
  double plant_mean_peak_base;
  double peak;
  double fsr_Toe;
  double torque_average;
} steps;

steps val_L;
steps val_R;
steps* L_p_steps = &val_L;
steps* R_p_steps = &val_R;

