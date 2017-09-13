#include "square.h"
#include "shape.h"
#include <iostream>
using namespace std;

   Square :: Square(int x, int y, int size) 
: Shape(x, y), m_size(size)

{
}


void Square :: draw(Grid &grid)
{
   for (int i = 0; i < m_size; i++)
   {
      for (int j = 0; j < m_size; j++)
      {
         if (i == 0 || j == 0)
         {
            grid.set(m_x + i, m_y+j, '*');
         }

         if (i == m_size - 1 || j == m_size - 1)
         {
            grid.set(m_x + i, m_y + j, '*');
         }
      }
   }
}
