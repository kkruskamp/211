#include <iostream>
#include <string>
#ifndef VIDEO_H
#define VIDEO_H
using namespace std;

class Video
{

  private:
    string m_title;
    string m_url;
    string m_comment;
    double m_length;
    int m_rating;

  public:
    Video(string title, string url, string comment, double length, int rating);
    void print();
    bool length_sort(Video *other);
    bool rating_sort(Video *other);
    bool title_sort(Video *other);
    string getTitle();

};

#endif
