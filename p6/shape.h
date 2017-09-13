#ifndef SHAPE_H
#define SHAPE_H
#include "grid.h"
#include <iostream>
using namespace std;

class Shape
{

   public:
      Shape(int x, int y);
      virtual void draw(Grid &grid) = 0;

   protected:
      int m_x;
      int m_y;

};
#endif
