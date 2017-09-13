#include <iostream>
using namespace std;
#include "list.h"

int main()
{
  List list;
  int numbers;

  while(cin >> numbers)
  {
    list.insert_at_end(numbers);
  }
  
  list.print();

  list.sum();

  cout << "sum = " << list.sum() << endl;

  return 0;
}
