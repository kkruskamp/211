#include <iostream>
#include "stdlib.h"
#include <ctype.h>
using namespace std;

bool legal_int(char *str)
{
  while (*str != 0)
  {
    if (!isdigit(*str))
    {
      cerr << "Error: illegal integer." << endl;
      exit(1);
    }
    str++;
  }

  return true;
}

int main(int argc, char *argv[])
{
  int total = 0;
  int value = 0;
  for (int i = 1; i < argc; i++)
  {

    value = atoi(argv[i]);
    if( legal_int(argv[i]) )
    {
      total += value;
    }
  }

  cout << total << endl;

  return 0;  

}
