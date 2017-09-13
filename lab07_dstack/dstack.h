#ifndef DSTACK_H
#define DSTACK_H
#include <iostream>
using namespace std;

class Stack
{
  
  public:
    Stack() {m_head = NULL;}
    ~Stack();
    void push(double value);
    bool pop(double &value);
    int size();
    bool empty();


  private:
  class Node
  {
    public:
      Node(double value, Node* next) 
      {m_value = value, m_next = next;}
      double m_value;
      Node* m_next;
  };
    Node *m_head;
    int m_length = 0;

};
#endif
