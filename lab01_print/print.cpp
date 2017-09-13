#include <iostream>
using namespace std;

int main()
{
  int value;
  string name = "hello";
  cin >> value;
  for (int i = 0; i < value; i++)
  {
    cout << i << " " << name << endl;
  }
  return 0;
}
