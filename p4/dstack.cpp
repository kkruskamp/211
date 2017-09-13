#include <iostream>
#include "dstack.h"
using namespace std;
Stack::Stack()
{
  m_head = NULL;
}
Stack :: ~Stack()
{
  Node* ptr = m_head;
  while(ptr != NULL)
  {
    Node * temp = ptr;
  ptr = ptr->m_next;
  delete temp;
  }
  delete ptr;
}

void Stack :: push(double value)
{
  m_head = new Node(value, m_head);
}

int Stack :: size()
{
  int counter = 0;
  Node* ptr = m_head;
  while (ptr != NULL)
  {
    counter++;
    ptr = ptr->m_next;
  }
  return counter;
}

bool Stack :: pop(double &value)
{
  Node* ptr = m_head;
  
  if (ptr == NULL)
  {
    return false;
  }

  value = m_head->m_value;
  m_head = m_head->m_next;
  delete ptr;
  return true;
}

bool Stack :: empty()
{
  if(m_head == NULL)
  {
    return true;
  }
  return false;
}
