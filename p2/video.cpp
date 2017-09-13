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

bool Video :: length_sort(Video *other_one)
{
  return m_length > other_one -> m_length;
}

bool Video :: rating_sort(Video *other_two)
{
  return m_rating < other_two -> m_rating;
}

bool Video :: title_sort(Video *other_three)
{
  return m_title > other_three -> m_title;
}

