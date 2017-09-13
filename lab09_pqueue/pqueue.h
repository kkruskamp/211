#include <iostream>
#include <string>
#include "cust.h"
#ifndef PQUEUE_H
#define PQUEUE_H
class Pqueue
{
  public:
    Pqueue();
    ~Pqueue();
    Cust* dequeue();
    void enqueue(Cust *cust, int priority);
    bool empty();

  private:

    class Node
    {
      public:
        Node(Cust *cust, int prio, Node *next)
        {
          m_cust = cust;
          m_next = next;
          m_prio = prio;
        }

        Cust *m_cust;
        Node *m_next;
        int m_prio;
    };

    Node* m_head;
    int m_cust_count = 0;
  
};

#endif
