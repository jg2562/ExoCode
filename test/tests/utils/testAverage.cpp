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
