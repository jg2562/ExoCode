#include "Utils.hpp"
#include "gtest/gtest.h"

TEST(utils_running_average_test, creation_test) {
	RunningAverage* runningAverage = new RunningAverage();
	delete runningAverage;
}

TEST(utils_running_average_test, initial_test) {
	RunningAverage* runningAverage = new RunningAverage(5);
	EXPECT_EQ(runningAverage->getAverage(),5);
	delete runningAverage;
}

TEST(utils_running_average_test, zero_initial_test) {
	RunningAverage* runningAverage = new RunningAverage();
	EXPECT_EQ(runningAverage->getAverage(),0);
	delete runningAverage;
}

TEST(utils_running_average_test, update_test) {
	RunningAverage* runningAverage = new RunningAverage();
	EXPECT_EQ(runningAverage->update(4),4);
	EXPECT_EQ(runningAverage->update(6),5);
	EXPECT_EQ(runningAverage->update(11),7);
	EXPECT_EQ(runningAverage->update(1),5.50);
	delete runningAverage;
}

TEST(utils_running_average_test, average_test) {
	RunningAverage* runningAverage = new RunningAverage();
	EXPECT_EQ(runningAverage->getAverage(),0);
	runningAverage->update(4);
	EXPECT_EQ(runningAverage->getAverage(),4);
	runningAverage->update(6);
	EXPECT_EQ(runningAverage->getAverage(),5);
	runningAverage->update(8);
	EXPECT_EQ(runningAverage->getAverage(),6);
	delete runningAverage;
}

TEST(utils_running_average_test, zero_reset_test) {
	RunningAverage* runningAverage = new RunningAverage();
	EXPECT_EQ(runningAverage->getAverage(),0);
	EXPECT_EQ(runningAverage->update(4),4);
	runningAverage->reset();
	EXPECT_EQ(runningAverage->getAverage(),0);
	delete runningAverage;
}

TEST(utils_running_average_test, initial_reset_test) {
	RunningAverage* runningAverage = new RunningAverage(5);
	EXPECT_EQ(runningAverage->getAverage(),5);
	EXPECT_EQ(runningAverage->update(15),10);
	runningAverage->reset(2);
	EXPECT_EQ(runningAverage->getAverage(),2);
	delete runningAverage;
}




TEST(utils_moving_average_test, creation_test) {
	MovingAverage* movingAverage = new MovingAverage(4);
	delete movingAverage;
}

TEST(utils_moving_average_test, update_test) {
	MovingAverage* movingAverage = new MovingAverage(4);
	EXPECT_EQ(movingAverage->update(12),3);
	EXPECT_EQ(movingAverage->update(4),4);
	EXPECT_EQ(movingAverage->update(32),12);
	EXPECT_EQ(movingAverage->update(2),12.5);
	EXPECT_EQ(movingAverage->update(-2),9);
	delete movingAverage;
}

TEST(utils_moving_average_test, average_test) {
	MovingAverage* movingAverage = new MovingAverage(4);
	EXPECT_EQ(movingAverage->getAverage(),0);
	EXPECT_EQ(movingAverage->update(12),3);
	EXPECT_EQ(movingAverage->getAverage(),3);
	delete movingAverage;
}

TEST(utils_moving_average_test, initial_test) {
	MovingAverage* movingAverage = new MovingAverage(4,10.0);
	EXPECT_EQ(movingAverage->getAverage(),10);
	EXPECT_EQ(movingAverage->update(2),8);
	delete movingAverage;
}

TEST(utils_moving_average_test, size_average_test) {
	MovingAverage* movingAverage = new MovingAverage(3);
	EXPECT_EQ(movingAverage->update(12),4);
	EXPECT_EQ(movingAverage->update(3),5);
	EXPECT_EQ(movingAverage->update(33),16);
	EXPECT_EQ(movingAverage->update(6),14);
	delete movingAverage;
}

TEST(utils_moving_average_test, reset_test) {
	MovingAverage* movingAverage = new MovingAverage(4);
	EXPECT_EQ(movingAverage->getAverage(),0);
	EXPECT_EQ(movingAverage->update(12),3);
	EXPECT_EQ(movingAverage->getAverage(),3);
	movingAverage->reset();
	EXPECT_EQ(movingAverage->getAverage(),0);
	delete movingAverage;
}

TEST(utils_moving_average_test, initial_reset_test) {
	MovingAverage* movingAverage = new MovingAverage(4,10);
	EXPECT_EQ(movingAverage->getAverage(),10);
	EXPECT_EQ(movingAverage->update(14),11);
	EXPECT_EQ(movingAverage->getAverage(),11);
	movingAverage->reset(4);
	EXPECT_EQ(movingAverage->getAverage(),4);
	delete movingAverage;
}
