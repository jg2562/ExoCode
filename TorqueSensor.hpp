#ifndef TORQUE_SENSOR_HEADER
#define TORQUE_SENSOR_HEADER

#include "Report.hpp"
#include "Port.hpp"
#include "Utils.hpp"

class TorqueSensor{
private:
  InputPort* torque_sensor_port;
  MovingAverage* torque_averager;
  RunningAverage* torque_calibration_average;
  double torque_calibration_value = 0;
  int torque_address;
  double torque_sign = 1.0;

  double measureRawTorque();
  double measureRawCalibratedTorque();
  void fillLocalReport(TorqueSensorReport* report);
public:
  double getTorque();
  TorqueSensor(InputPort* torque_sensor_port);
  void measureTorque();
  void startTorqueCalibration();
  void updateTorqueCalibration();
  void endTorqueCalibration();
  void setSign(int sign);
  TorqueSensorReport* generateReport();
  void fillReport(TorqueSensorReport* report);
};

#endif
