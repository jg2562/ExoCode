#include <gmock/gmock.h>
#include "Port.hpp"

class MockTxPort : public TxPort {
public:
	MockTxPort(): TxPort(0){};
	MOCK_METHOD(unsigned int, getPin, ());
	MOCK_METHOD(void, write, (double));
};

class MockRxPort : public RxPort {
public:
	MockRxPort(): RxPort(0){};
	MOCK_METHOD(unsigned int, getPin, ());
	MOCK_METHOD(double, read, ());
};

class MockImuPort : public ImuPort {
public:
	MockImuPort(): ImuPort(I2C_PINS_3_4){};
	MOCK_METHOD(i2c_pins, getPins, ());
	MOCK_METHOD(i2c_bus, getBus, ());
};
