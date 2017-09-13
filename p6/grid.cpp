//SHAPES
//KRUSKAMP, KYLE
//KKRUSKAMP
#include"grid.h"
#include<iostream>

using namespace std;

Grid::Grid()
{
   for(int i = 0; i < 60; i++)
   {
      for(int j = 0; j < 24; j++)
      {
         m_grid[i][j] = ' ';
      }
   }
}

void Grid::print()
{
   for(int i = 0; i < 24; i++)
   {
      for(int j = 0; j < 60; j++)
      {
         cout<< m_grid[j][i];
      }

      cout << endl;
   }
}

void Grid::set(int x, int y, char ch)
{
   if(y < 24 && x < 60)
   {
      m_grid[x][y] = ch;
   }
}
