//Video rating system
//Kruskamp, Kyle
//kkruskamp

#include <iostream>
#include <string>
#include <algorithm>
#include "video.h"
using namespace std;

int main()
{
  const int max = 100;
  Video *videos[max];
  int video_amount = 0;
  int rating;
  string comment, title, url, sort_by;
  double length;

  getline(cin, sort_by);

  while (getline(cin, title))
  {   
    if (video_amount == 100)
    {
      cerr << "Too many videos, giving up." << endl;
      return 1;
    }
    getline(cin, url);
    getline(cin, comment);
    cin >> length;
    cin >> rating;
    cin.ignore(); 
    videos[video_amount] = new Video(title,url,comment,length,rating);
    video_amount++;
  }

  if (sort_by == "rating")
  {
    for (int last = video_amount - 1; last > 0; last--)
    {
      for (int cur = 0; cur < last; cur++)
      {
        if (videos[cur] -> rating_sort(videos[cur+1]))
        {
          swap(videos[cur], videos[cur+1]);
        }
      }
    }
  }

  else if (sort_by == "length")
  {
    for (int last = video_amount - 1; last > 0; last--)
    {
      for (int cur = 0; cur < last; cur++)
      {
        if (videos[cur] -> length_sort(videos[cur+1]))
        {
          swap(videos[cur], videos[cur+1]);
        }  
      }
    }
  }

  else if (sort_by == "title")
  {
    for (int last = video_amount - 1; last > 0; last--)
    {
      for (int cur = 0; cur < last; cur++)
      {
        if (videos[cur] -> title_sort(videos[cur+1]))
        {
          swap(videos[cur], videos[cur+1]);
        }
      }
    }
  }
  else
  {
    cerr << sort_by << " is not a legal sorting method, giving up." << endl;
    return 1;
  }
  for (int i = 0; i < video_amount; i++)
  {
    videos[i]-> print();
  }

  return 0;

}
