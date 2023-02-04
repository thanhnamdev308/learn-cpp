// test.cpp
#include "function_need_to_test.h"
#include <gtest/gtest.h>
 
TEST (RectangleAreaTest, InvalidParam) { 
    EXPECT_EQ(0, rectangleArea(-1, 5));
    EXPECT_EQ(0, rectangleArea(10, -2));
    EXPECT_EQ(0, rectangleArea(0, 0));
}
 
TEST(RectangleAreaTest, ValidParam) {
    EXPECT_EQ(20, rectangleArea(4, 5));
    EXPECT_EQ(10, rectangleArea(5, 2));
    EXPECT_EQ(56, rectangleArea(7, 8));
}
 
int main(int argc, char **argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
