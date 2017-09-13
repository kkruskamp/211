#include <iostream>
using namespace std;
#include "list.h"

// on some machines member variables are not automatically initialized to 0
List::List()
{
  m_head = NULL;
}

// delete all Nodes in the list
// since they are dynamically allocated using new, they won't go away
// automatically when the list is deleted
// Rule of thumb: destructor deletes all memory created by member functions
List::~List()
{
  // cout << "List::~List() was called" << endl;

  Node *ptr = m_head;
  while (ptr != NULL)
  {
    Node *temp;

    temp = ptr;
    ptr = ptr->m_next;
    delete temp;
  }
}

// always insert at the front of the list
// Note: this works even in the SPECIAL CASE that the list is empty
void List::insert(int value)
{
  m_head = new Node(value, m_head);
}

void List::insert_at_end(int value)
{

  if (m_head == NULL)
  {
    m_head = new Node(value, NULL);
  }
  else
  {
    Node *ptr = m_head;

    while (ptr != NULL)
    {
      if (ptr->m_next == NULL)
      {
        ptr->m_next = new Node(value, NULL);
        return;

      }
      ptr = ptr->m_next;

    }
  } 
}
// iterate through all the Nodes in the list and print each Node
void List::print()
{
  Node *ptr = m_head; 
  while (ptr != NULL)
  {
    cout << ptr->m_value << endl; 
    ptr = ptr->m_next;
  }

  /* The following is the same as the above loop
     for (Node *ptr = m_head; ptr; ptr = ptr->m_next)
     {
     cout << ptr->m_value << endl; 
     }
     */
}

int List :: sum()
{ 
  m_sum = 0;
  Node *ptr = m_head;
  while (ptr != NULL)
  {
    m_sum = m_sum + ptr->m_value;
    ptr = ptr->m_next;
  }
  return m_sum;
}
