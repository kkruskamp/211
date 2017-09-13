#ifndef VLIST_H
#define VLIST_H
#include "video.h"
#include <iostream>
using namespace std;

class List
{
  public:
    
    List();
    ~List();
    bool insert(Video* new_video);
    bool remove(string target);
    void print();
    int getCount();
    bool lookup(string title);

  private:
    
    class Node
    {
      public:
        Node(Video* new_video, Node* next)
        {m_video = new_video; m_next = next;}
        Video* m_video;
        Node *m_next;
    };

    Node *m_head;
    int m_video_count = 0;
};

#endif
