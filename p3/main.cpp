//Linked List
//Kruskamp, Kyle
//kkruskamp

#include <iostream>
#include <string>
#include "vlist.h"
#include "video.h"
using namespace std;

int main()
{
  int rating;
  string comment, title, url, sort_by;
  double length;
  List list;
  bool whatHappened;
  while (getline(cin, sort_by))
  {

    if (sort_by == "insert")
    {
      getline(cin, title);
      getline(cin, url);
      getline(cin, comment);
      cin >> length;
      cin >> rating;
      cin.ignore(); 
      whatHappened = list.insert(new Video(title,url,comment,length,rating));
      if (whatHappened == false)
      {
        cerr << "Could not insert <" << title << ">, already in list." << endl;

      }
    }
    else if (sort_by == "length")
    {
      cout << list.getCount() << endl;
    }

    else if (sort_by == "print")
    { 
      list.print();
    }

    else if (sort_by == "remove")
    {
      getline(cin, title);
      whatHappened = list.remove(title);
      if(whatHappened == false)
      {
        cerr << "Title <" << title << "> not in list, could not delete." << endl;
      }

    }

    else if (sort_by == "lookup")
    {
      getline(cin, title);
      whatHappened = list.lookup(title);
      if(whatHappened == false)
      {
        cerr << "Title <" << title << "> not in list." << endl;
      }
    }
    
    else 
    {
      cerr << "<" << sort_by << "> is not a legal command, giving up." << endl;
      return 1;
    }
  
  }

  return 0;


}
