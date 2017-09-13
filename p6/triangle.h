#include "grid.h"
#include "shape.h"
#include <iostream>
using namespace std;

class Triangle : public Shape
{
   public:
      Triangle(int x, int y);
      void draw(Grid &grid);

};
