#include "circle.h"
#include <iostream>
using namespace std;

   Circle :: Circle(int x, int y) 
: Shape(x, y)
{
}

void Circle :: draw (Grid &grid)
{
   // i is my y term because im fucking stoopid and dont take physics
   for (int i = 0; i < 4; i++)
   {
      // j is my x term for the same reasons as above
      for (int j = 0; j < 4; j++)
      {
         if ((j == 1 || j == 2) && i == 0)
         {
            grid.set(m_x + j, m_y + i, 'o');
 //           cout << "a" <<endl;
         }
//cout << "1" <<endl;
         if (i == 1 && (j == 0 || j == 3))
         {
            grid.set(m_x + j, m_y + i, 'o');
    //        cout << "b" <<endl;
         }
//cout << "2" <<endl;
         if (i == 2 && (j == 0 || j == 3))
         {
            grid.set(m_x + j, m_y + i, 'o');
      //      cout << "c" <<endl;
         }
//cout << "3" <<endl;
         if (i == 3 && (j == 1 || j == 2))
         {
        //    cout << "d" <<endl;
            grid.set(m_x + j, m_y + i, 'o');
         }
//cout << "4" <<endl;
      }
    // cout << i << endl;
   }
}
