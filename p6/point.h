#ifndef POINT_H
#define POINT_H
#include "shape.h"
#include "grid.h"
#include <iostream>
using namespace std;

class Point : public Shape
{
   public:
      Point(int x, int y, char c);
      void draw(Grid &grid);
   private:
      char m_c;
};
#endif
