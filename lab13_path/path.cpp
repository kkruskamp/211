#include "location.h"
#include <iostream>
#include <vector>
using namespace std;

int main()
{
   double lat, lon;
   vector <Location*> location;
   while (cin >> lat)
   {
      cin >> lon;
      location.push_back(new Location(lat, lon));
   }

   for (unsigned int i = 0; i < location.size(); i++)
   {
      location[i]->print(cout);
      cout << endl;
   }
}
