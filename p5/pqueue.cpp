#include <iostream>
#include "pqueue.h"
#include "cust.h"
using namespace std;

Pqueue :: Pqueue()
{
   m_head = NULL;
}

Pqueue :: ~Pqueue()
{
   Node *ptr = m_head;

   while(ptr != NULL)
   {
      Node *temp;
      temp = ptr;
      ptr = ptr->m_next;
      delete temp;
   }
}

int Pqueue :: getArrival()
{
   if (m_head == NULL)
   {
      return 0;
   }
   return m_head->m_prio;
}

void Pqueue :: enqueue(Cust *cust, int priority)
{
   Node *ptr = m_head;
   m_cust_count++;

   if (m_head == NULL || priority < ptr->m_prio)
   {
      m_head = new Node(cust, priority, m_head);
   }

   else
   {

      Node *ptr = m_head;

      while (ptr->m_next != NULL && priority >= ptr->m_next->m_prio)
      {
         ptr = ptr->m_next;
      }

      ptr->m_next = new Node(cust, priority, ptr->m_next);

   }
}

Cust *Pqueue :: dequeue()
{
   Node *ptr = m_head;
   Cust *cust;
   if (m_head == NULL)
   {
      return NULL;
   }

   else
   {
      m_head = ptr->m_next;
      cust = ptr->m_cust;
      delete ptr;
      m_cust_count--;
   }
   ptr = ptr->m_next;
   return cust;
}


bool Pqueue :: empty()
{
   Node *ptr = m_head;

   if (ptr == NULL)
   {
      return true;
   }

   return false;
}

int Pqueue :: size()
{
   return m_cust_count;
}
