#ifndef EXOSKELETON_HEADER
#define EXOSKELETON_HEADER
#include "Leg.hpp"
#include "Pins.hpp"

class Exoskeleton{
private:
public:
  Leg* left_leg;
  Leg* right_leg;

  Exoskeleton(ExoPins* exoPins);
  void initialize();
  void measureSensors();
  bool checkMotorErrors();
  void takeFSRBaseline();
  void disableExo();
  void applyTorque();
  void applyStateMachine();
  void adjustControl();
  void resetStartingParameters();
  void setZeroIfSteadyState();
  void calibrateTorque();
  void calibrateFSRs();
  void setZeroIfStateState();
};

#endif
