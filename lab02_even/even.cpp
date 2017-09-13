#include <iostream>
using namespace std;

int main()
{
  int value;
  bool all_even = true;

  while (cin >> value)
  {
    if (value % 2 != 0)
    {
      all_even = false;
    }
  }
  
  if (all_even == true)
  {  
    cout << "all even" << endl;
    return 0;
  }


  else
  {
    cerr << "not all even" << endl;
    return 1;

  }

}


