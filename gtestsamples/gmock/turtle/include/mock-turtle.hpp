// Copyright 2022 NguyenThanhNam [legal/copyright]
#ifndef MOCK_TURTLE_HPP
#define MOCK_TURTLE_HPP
#include <gmock/gmock.h>  // Brings in gMock..

#include "turtle.hpp"

class MockTurtle : public Turtle {
 public:
  MOCK_METHOD(void, PenUp, (), (override));
  MOCK_METHOD(void, PenDown, (), (override));
  MOCK_METHOD(void, Forward, (int distance), (override));
  MOCK_METHOD(void, Turn, (int degrees), (override));
  MOCK_METHOD(void, GoTo, (int x, int y), (override));
  MOCK_METHOD(int, GetX, (), (const, override));
  MOCK_METHOD(int, GetY, (), (const, override));
};
#endif  // MOCK_TURTLE_HPP
