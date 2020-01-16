#ifndef UTILITES_HEADER
#define UTILITES_HEADER

/**
 * @brief Virtual class for an average
 *
 * A virtual class to allow for a generic average
 */
class Average{
public:

  /**
   * @brief Cleans up average
   */
  virtual ~Average();

  /**
   * @brief Update the average with the next value
   * @param value The next value
   */
  virtual double update(double value) = 0;

  /**
   * @brief Return the current average value
   */
  virtual double getAverage() = 0;

  /**
   * @brief Reset the average to zero
   */
  virtual void reset() = 0;

  /**
   * @brief Reset the average to the value
   * @param value The initial value to reset to
   */
  virtual void reset(double value) = 0;
};

/**
 * @brief Utility for a running average
 *
 * RunningAverage will keep accumulating values until a reset
 */
class RunningAverage:public Average{
private:
  double avg;
  double count;
public:
  /**
   * @brief The constructor with an initial value of zero
   */
  RunningAverage();

  /**
   * @brief The constructor with ability to set initial value
   * @param initial The initial value the running average should start with
   */
  RunningAverage(double initial);

  /**
   * @brief Update the running average with the next value
   * @param value The next value
   */
  double update(double value);

  /**
   * @brief Return the current average value
   */
  double getAverage();

  /**
   * @brief Reset the average to zero
   */
  void reset();

  /**
   * @brief Reset the average to the value
   * @param value The initial value to reset to
   */
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
