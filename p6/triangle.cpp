#include "triangle.h"
#include <iostream>
using namespace std;

   Triangle :: Triangle(int x, int y) 
: Shape(x, y)
{
}

void Triangle :: draw (Grid &grid)
{
   for (int i = 0; i < 3; i++)
   {
      for (int j = 0; j < 5; j++)
      {
         if (i == 0 && j == 2)
         {
            grid.set(m_x + j, m_y + i, '+');
         }

         if (i == 1 && (j == 1 || j == 3))
         {
            grid.set(m_x + j, m_y + i, '+');
         }

         if (i == 2 && (j == 0 || j == 1 || j == 2 || j == 3 || j == 4))
         {
            grid.set(m_x + j, m_y + i, '+');
         }


      }
   }
}
