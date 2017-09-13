#include "location.h"
#include <iostream>
#include <vector>
#include <map>
using namespace std;

int main()
{
   double lon;
   double lat;
   string title;
   map <string, Location *> my_map;
   while (cin >> lat)
   {  
      if (lat != 0)
      {
         cin >> lon;
         cin >> title;
         my_map[title] = new Location(lat, lon);
      }

      else
      {
         while (cin >> title)
         {

            map<string, Location*> :: iterator iter = my_map.find(title);

            if (iter != my_map.end())
            {
               cout << title << " is at "; 
               iter->second->print(cout);
               cout << endl;
            }
            else
            {
               cout << title << " not in database" << endl;
            }


         }
      }
   }
}


