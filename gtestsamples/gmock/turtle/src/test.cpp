// Copyright 2022 NguyenThanhNam [legal/copyright]
#include <gmock/gmock.h>
#include <gtest/gtest.h>

#include "include/mock-turtle.hpp"
#include "include/painter.hpp"

using ::testing::AtLeast;  // #1

TEST(PainterTest, CanDrawSomething) {
  MockTurtle turtle;              // #2
  EXPECT_CALL(turtle, PenDown())  // #3
      .Times(AtLeast(1));

  Painter painter(turtle);  // #4

  EXPECT_TRUE(painter.DrawCircle(0, 0, 10));  // #5
}

int main(int argc, char **argv) {
  testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
