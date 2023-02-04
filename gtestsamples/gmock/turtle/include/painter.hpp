// Copyright 2022 NguyenThanhNam [legal/copyright]
#ifndef PAINTER_HPP
#define PAINTER_HPP
#include "turtle.hpp"

class Painter {
 public:
  Turtle *m_turtle;
  Painter(Turtle &turtle) {
    m_turtle = &turtle;
  }
  bool DrawCircle(const int &, const int &, const int &){
    m_turtle->PenDown();
    return true;    
  }
};
#endif  // PAINTER_HPP
