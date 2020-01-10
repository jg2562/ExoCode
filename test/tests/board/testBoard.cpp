#include "Board.hpp"
#include "gtest/gtest.h"

#include "mockInputPort.hpp"
#include "mockOutputPort.hpp"
#include "mockSpecialPort.hpp"

TEST(board_test, creation_test) {
	Board* board = new Board();
	delete board;
}

TEST(board_test, fsr_sense_left_toe_test) {
	MockInputPort* mock_port = new MockInputPort();
	Board* board = new Board();
	EXPECT_EQ(board->takeFsrSenseLeftToePort(), nullptr);
	board->setFsrSenseLeftToePort(mock_port);
	EXPECT_EQ(board->takeFsrSenseLeftToePort(), mock_port);
	EXPECT_EQ(board->takeFsrSenseLeftToePort(), nullptr);
	delete board;
	delete mock_port;
}

TEST(board_test, fsr_sense_left_heel_test) {
	MockInputPort* mock_port = new MockInputPort();
	Board* board = new Board();
	EXPECT_EQ(board->takeFsrSenseLeftToePort(), nullptr);
	board->setFsrSenseLeftToePort(mock_port);
	EXPECT_EQ(board->takeFsrSenseLeftToePort(), mock_port);
	EXPECT_EQ(board->takeFsrSenseLeftToePort(), nullptr);
	delete board;
	delete mock_port;
}

TEST(board_test, fsr_sense_right_toe_test) {
	MockInputPort* mock_port = new MockInputPort();
	Board* board = new Board();
	EXPECT_EQ(board->takeFsrSenseRightToePort(), nullptr);
	board->setFsrSenseRightToePort(mock_port);
	EXPECT_EQ(board->takeFsrSenseRightToePort(), mock_port);
	EXPECT_EQ(board->takeFsrSenseRightToePort(), nullptr);
	delete board;
	delete mock_port;
}

TEST(board_test, fsr_sense_right_heel_test) {
	MockInputPort* mock_port = new MockInputPort();
	Board* board = new Board();
	EXPECT_EQ(board->takeFsrSenseRightToePort(), nullptr);
	board->setFsrSenseRightToePort(mock_port);
	EXPECT_EQ(board->takeFsrSenseRightToePort(), mock_port);
	EXPECT_EQ(board->takeFsrSenseRightToePort(), nullptr);
	delete board;
	delete mock_port;
}

TEST(board_test, torque_sensor_left_ankle_test) {
	MockInputPort* mock_port = new MockInputPort();
	Board* board = new Board();
	EXPECT_EQ(board->takeTorqueSensorLeftAnklePort(), nullptr);
	board->setTorqueSensorLeftAnklePort(mock_port);
	EXPECT_EQ(board->takeTorqueSensorLeftAnklePort(), mock_port);
	EXPECT_EQ(board->takeTorqueSensorLeftAnklePort(), nullptr);
	delete board;
	delete mock_port;
}

TEST(board_test, torque_sensor_left_knee_test) {
	MockInputPort* mock_port = new MockInputPort();
	Board* board = new Board();
	EXPECT_EQ(board->takeTorqueSensorLeftKneePort(), nullptr);
	board->setTorqueSensorLeftKneePort(mock_port);
	EXPECT_EQ(board->takeTorqueSensorLeftKneePort(), mock_port);
	EXPECT_EQ(board->takeTorqueSensorLeftKneePort(), nullptr);
	delete board;
	delete mock_port;
}

TEST(board_test, torque_sensor_right_ankle_test) {
	MockInputPort* mock_port = new MockInputPort();
	Board* board = new Board();
	EXPECT_EQ(board->takeTorqueSensorRightAnklePort(), nullptr);
	board->setTorqueSensorRightAnklePort(mock_port);
	EXPECT_EQ(board->takeTorqueSensorRightAnklePort(), mock_port);
	EXPECT_EQ(board->takeTorqueSensorRightAnklePort(), nullptr);
	delete board;
	delete mock_port;
}

TEST(board_test, torque_sensor_right_knee_test) {
	MockInputPort* mock_port = new MockInputPort();
	Board* board = new Board();
	EXPECT_EQ(board->takeTorqueSensorRightKneePort(), nullptr);
	board->setTorqueSensorRightKneePort(mock_port);
	EXPECT_EQ(board->takeTorqueSensorRightKneePort(), mock_port);
	EXPECT_EQ(board->takeTorqueSensorRightKneePort(), nullptr);
	delete board;
	delete mock_port;
}

TEST(board_test, pot_left_ankle_test) {
	MockInputPort* mock_port = new MockInputPort();
	Board* board = new Board();
	EXPECT_EQ(board->takePotLeftAnklePort(), nullptr);
	board->setPotLeftAnklePort(mock_port);
	EXPECT_EQ(board->takePotLeftAnklePort(), mock_port);
	EXPECT_EQ(board->takePotLeftAnklePort(), nullptr);
	delete board;
	delete mock_port;
}

TEST(board_test, pot_left_knee_test) {
	MockInputPort* mock_port = new MockInputPort();
	Board* board = new Board();
	EXPECT_EQ(board->takePotLeftKneePort(), nullptr);
	board->setPotLeftKneePort(mock_port);
	EXPECT_EQ(board->takePotLeftKneePort(), mock_port);
	EXPECT_EQ(board->takePotLeftKneePort(), nullptr);
	delete board;
	delete mock_port;
}

TEST(board_test, pot_right_ankle_test) {
	MockInputPort* mock_port = new MockInputPort();
	Board* board = new Board();
	EXPECT_EQ(board->takePotRightAnklePort(), nullptr);
	board->setPotRightAnklePort(mock_port);
	EXPECT_EQ(board->takePotRightAnklePort(), mock_port);
	EXPECT_EQ(board->takePotRightAnklePort(), nullptr);
	delete board;
	delete mock_port;
}

TEST(board_test, pot_right_knee_test) {
	MockInputPort* mock_port = new MockInputPort();
	Board* board = new Board();
	EXPECT_EQ(board->takePotRightKneePort(), nullptr);
	board->setPotRightKneePort(mock_port);
	EXPECT_EQ(board->takePotRightKneePort(), mock_port);
	EXPECT_EQ(board->takePotRightKneePort(), nullptr);
	delete board;
	delete mock_port;
}

TEST(board_test, motor_left_ankle_test) {
	MockOutputPort* mock_port = new MockOutputPort();
	Board* board = new Board();
	EXPECT_EQ(board->takeMotorLeftAnklePort(), nullptr);
	board->setMotorLeftAnklePort(mock_port);
	EXPECT_EQ(board->takeMotorLeftAnklePort(), mock_port);
	EXPECT_EQ(board->takeMotorLeftAnklePort(), nullptr);
	delete board;
	delete mock_port;
}

TEST(board_test, motor_right_ankle_test) {
	MockOutputPort* mock_port = new MockOutputPort();
	Board* board = new Board();
	EXPECT_EQ(board->takeMotorRightAnklePort(), nullptr);
	board->setMotorRightAnklePort(mock_port);
	EXPECT_EQ(board->takeMotorRightAnklePort(), mock_port);
	EXPECT_EQ(board->takeMotorRightAnklePort(), nullptr);
	delete board;
	delete mock_port;
}

TEST(board_test, motor_left_knee_test) {
	MockOutputPort* mock_port = new MockOutputPort();
	Board* board = new Board();
	EXPECT_EQ(board->takeMotorLeftKneePort(), nullptr);
	board->setMotorLeftKneePort(mock_port);
	EXPECT_EQ(board->takeMotorLeftKneePort(), mock_port);
	EXPECT_EQ(board->takeMotorLeftKneePort(), nullptr);
	delete board;
	delete mock_port;
}

TEST(board_test, motor_right_knee_test) {
	MockOutputPort* mock_port = new MockOutputPort();
	Board* board = new Board();
	EXPECT_EQ(board->takeMotorRightKneePort(), nullptr);
	board->setMotorRightKneePort(mock_port);
	EXPECT_EQ(board->takeMotorRightKneePort(), mock_port);
	EXPECT_EQ(board->takeMotorRightKneePort(), nullptr);
	delete board;
	delete mock_port;
}

TEST(board_test, led_creation_test) {
	MockOutputPort* mock_port = new MockOutputPort();
	Board* board = new Board();
	EXPECT_EQ(board->takeLedPort(), nullptr);
	board->setLedPort(mock_port);
	EXPECT_EQ(board->takeLedPort(), mock_port);
	EXPECT_EQ(board->takeLedPort(), nullptr);
	delete board;
	delete mock_port;
}

TEST(board_test, led_turn_on_test) {
	MockOutputPort* mock_port = new MockOutputPort();
	Board* board = new Board();
	board->turnOnLed();
	board->setLedPort(mock_port);
	EXPECT_CALL(*mock_port, write(1))
		.Times(1);
	board->turnOnLed();
	EXPECT_EQ(board->takeLedPort(), mock_port);
	board->turnOnLed();
	delete board;
	delete mock_port;
}

TEST(board_test, imu_address_0_test) {
	Board* board = new Board();
	board->setImuAddress0(5);
	EXPECT_EQ(board->getImuAddress0(), 5);
	delete board;
}

TEST(board_test, imu_address_1_test) {
	Board* board = new Board();
	board->setImuAddress1(5);
	EXPECT_EQ(board->getImuAddress1(), 5);
	delete board;
}

TEST(board_test, bluetooth_rx_test) {
	MockRxPort* mock_port = new MockRxPort();
	Board* board = new Board();
	EXPECT_EQ(board->takeBluetoothRxPort(), nullptr);
	board->setBluetoothRxPort(mock_port);
	EXPECT_EQ(board->takeBluetoothRxPort(), mock_port);
	EXPECT_EQ(board->takeBluetoothRxPort(), nullptr);
	delete board;
	delete mock_port;
}

TEST(board_test, bluetooth_tx_test) {
	MockTxPort* mock_port = new MockTxPort();
	Board* board = new Board();
	EXPECT_EQ(board->takeBluetoothTxPort(), nullptr);
	board->setBluetoothTxPort(mock_port);
	EXPECT_EQ(board->takeBluetoothTxPort(), mock_port);
	EXPECT_EQ(board->takeBluetoothTxPort(), nullptr);
	delete board;
	delete mock_port;
}

TEST(board_test, imu_slot_0_test) {
	MockImuPort* mock_port = new MockImuPort();
	Board* board = new Board();
	EXPECT_EQ(board->getImuSlot0(), nullptr);
	board->setImuSlot0(mock_port);
	EXPECT_EQ(board->getImuSlot0(), mock_port);
	EXPECT_EQ(board->getImuSlot0(), mock_port);
	delete board;
}

TEST(board_test, imu_slot_1_test) {
	MockImuPort* mock_port = new MockImuPort();
	Board* board = new Board();
	EXPECT_EQ(board->getImuSlot1(), nullptr);
	board->setImuSlot1(mock_port);
	EXPECT_EQ(board->getImuSlot1(), mock_port);
	EXPECT_EQ(board->getImuSlot1(), mock_port);
	delete board;
}

TEST(board_test, imu_slot_2_test) {
	MockImuPort* mock_port = new MockImuPort();
	Board* board = new Board();
	EXPECT_EQ(board->getImuSlot2(), nullptr);
	board->setImuSlot2(mock_port);
	EXPECT_EQ(board->getImuSlot2(), mock_port);
	EXPECT_EQ(board->getImuSlot2(), mock_port);
	delete board;
}
