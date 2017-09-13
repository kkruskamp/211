#ifndef CIRCLE_H
#define CIRCLE_H
#include "shape.h"
#include "grid.h"
#include <iostream>
using namespace std;

class Circle : public Shape
{
   public:
      Circle(int x, int y);
      void draw(Grid &grid);

};

#endif
