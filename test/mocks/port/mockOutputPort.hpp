#include <gmock/gmock.h>
#include "Port.hpp"

class MockOutputPort : public OutputPort {
public:
	MockOutputPort(): OutputPort(0){};
	MOCK_METHOD(void, write, (double));
};
