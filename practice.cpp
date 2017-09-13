#include <iostream>
#include <vector>
#include <string>

using namespace std;

int max_len(vector<string> &vec)
{  
   unsigned int largest = 0;

   for (int i = 0; i != vec.size(); i++)
   {
      if (vec[i].length() > largest)
      {
         largest = vec[i].length();
      }
   }
   return largest;
}

int main()
{
   vector<string> vec;
   string str;
   int largest = 0;

   while(cin >> str)
   {
      if (str == "quit")
      {
         break;
      }

      else
      {
         vec.push_back(str);
      }
   
   }
   
   largest = max_len(vec);
   cout << largest << endl;
   return 0;
}
