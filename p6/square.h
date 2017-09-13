#ifndef SQUARE_H
#define SQUARE_H
#include "shape.h"
#include "grid.h"
#include <iostream>
using namespace std;

class Square : public Shape
{
   public:
      Square(int x, int y, int size);
      void draw(Grid &grid);

   private:
      int m_size;
};
#endif
