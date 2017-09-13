#include <iostream>
#include "video.h"
#include "vlist.h"
using namespace std;

int List :: getCount()
{
  return m_video_count;
}

List :: List()
{
  m_head = NULL;
}

List :: ~List()
{
  //  cout << "~List was called" << endl;
  Node *ptr = m_head;

  while (ptr != NULL)
  {
    Node *temp;
    temp = ptr;
    ptr = ptr->m_next;
    delete temp;
  }
}

bool List :: insert(Video *new_video)
{
  m_video_count++;
  if (m_head == NULL || new_video->getTitle() < m_head->m_video->getTitle())
  {
    m_head = new Node(new_video, m_head);
      return true;
  }

  else
  {
    Node *ptr = m_head;
    while(ptr->m_next != NULL && new_video->getTitle() > ptr->m_next->m_video->getTitle())
    {
      ptr = ptr->m_next;
    }
    if(ptr->m_video == new_video)
    {
      return false;
    }
    ptr->m_next = new Node(new_video, ptr->m_next);
    return true;
  }
}

void List :: print()
{

  Node *ptr = m_head;

  while (ptr != NULL)
  {
    ptr->m_video->print();
    ptr = ptr->m_next;
  }

}

bool List :: lookup(string title)
{

  Node* ptr = m_head;

  while( ptr != NULL)
  {
    if (title == ptr->m_video->getTitle())
    {
      ptr->m_video->print();
      return true;
    }
    ptr = ptr->m_next;
  }
  return false;
}

bool List :: remove(string target)
{

  Node* ptr = m_head;

  if (m_head == NULL)
  {
    return false;
  }

  if(m_head->m_video->getTitle() == target)
  {
    Node* temp = m_head;
    m_head = m_head->m_next;
    delete temp;
    return true;
  }

  while(ptr->m_next != NULL)
  {
    if (ptr->m_next->m_video->getTitle() == target)
    {
      Node* temp = ptr->m_next;
      ptr->m_next = ptr->m_next->m_next;
      delete temp;
      return true;
    }

    ptr = ptr->m_next;

  }
  return false;
}













