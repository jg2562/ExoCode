#ifndef UTILITES_HEADER
#define UTILITES_HEADER

class Average{
public:
  virtual ~Average();
  virtual double update(double value) = 0;
  virtual double getAverage() = 0;
  virtual void reset() = 0;
  virtual void reset(double value) = 0;
};

class RunningAverage:public Average{
private:
  double avg;
  double count;
public:
  RunningAverage();
  RunningAverage(double initial);
  double update(double value);
  double getAverage();
  void reset();
  void reset(double value);
};

class MovingAverage: public Average{
private:
  double* previous_values;
  double total;
  double average;
  int index;
  int size;
public:
  MovingAverage(int size, double initial=0.0);
  ~MovingAverage();
  double update(double value);
  double getAverage();
  void reset();
  void reset(double value);
};

/**
 * @brief A class to clamp values.
 *
 * The clamp class will always clamp the given value between the upper and lower values given.
 */
class Clamp{
private:
  double upper; /**< The upper value */
  double lower; /**< The lower value */
public:
  /**
   * @brief The constructor with upper and lower bounds.
   * @param lower The lower bound that the value can't be lower than
   * @param upper The upper bound that the value can't be higher than
   */
  Clamp(double lower, double upper);

  /**
   * @brief Clamps the value between lower and upper.
   * @param value The value to be clamped
   * @return The clamped value
   */
  double clamp(double value);
};

class Threshold{
private:
  double upper_threshold;
  double lower_threshold;
  bool state;
public:
  Threshold(bool starting_state, double upper_threshold_value, double lower_threshold_value);
  bool getState(double value);
  void setUpperThreshold(double value);
  void setLowerThreshold(double value);
};

class Timer{
private:
  unsigned long start_time;
  unsigned long pause_time;
public:
  Timer();
  double lap();
  double lapSec();
  void reset();
  void pause();
  void resume();
};

class Chrono{
private:
  unsigned long start_time, interval_time;
public:
  Chrono(unsigned long interval);
  bool check();
  void reset();
};

class Max{
private:
  double maxVal;
public:
  Max();
  double getMax();
  void update(double value);
  void reset();
};

class Min{
private:
  double minVal;
public:
  Min();
  double getMin();
  void update(double value);
  void reset();
};

class ChangeTrigger{
private:
  bool state;
public:
  ChangeTrigger(bool start_state);
  bool update(bool state);
};


class Range{
private:
  Max* maximum;
  Min* minimum;
  RunningAverage* min_avg;
  RunningAverage* max_avg;
  double threshold;
  double calculateThreshold();
public:
  Range(double first_min, double first_max);
  double getMax();
  double getMin();
  void update(double value);
  void reset(double min, double max);
  void reset();
};

void updateMax(double* max_val, double val);

#endif
