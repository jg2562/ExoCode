#include "Board.hpp"
#include "gtest/gtest.h"

TEST(board_test, creation_test) {
	Board* board = new Board();
	delete board;
}

