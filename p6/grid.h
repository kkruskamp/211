#ifndef GRID_H
#define GRID_H

#include<iostream>
using namespace std;

class Grid
{
   public:
      Grid();
      void print();
      void set(int x, int y, char ch);

   private:
      char m_grid[60][24];
};
#endif

