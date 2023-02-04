// Copyright 2022 NguyenThanhNam [legal/copyright]
#ifndef TURTLE_HPP
#define TURTLE_HPP

class Turtle {
 public:
  virtual ~Turtle() {}
  virtual void PenUp() = 0;
  virtual void PenDown() = 0;
  virtual void Forward(int distance) = 0;
  virtual void Turn(int degrees) = 0;
  virtual void GoTo(int x, int y) = 0;
  virtual int GetX() const = 0;
  virtual int GetY() const = 0;
};
#endif  // TURTLE_HPP
