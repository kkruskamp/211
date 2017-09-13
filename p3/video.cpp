#include <iostream>
#include "video.h"
using namespace std;

Video :: Video(string title, string url, string comment, double length, int rating)
{
  m_title = title;
  m_url = url;
  m_comment = comment;
  m_length = length;
  m_rating = rating;
}

void Video :: print()
{
  
  cout << m_title << ", " << m_url << ", " << m_comment << ", " << m_length << ", ";

  for (int i = 0; i < m_rating; i++)
  {
    cout << "*";
  }

  cout << endl;

}

string Video :: getTitle()
{
  return m_title;
}
