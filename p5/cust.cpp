#include "cust.h"
#include <assert.h>
#include <fstream>
#include <iostream>
using namespace std;

Cust::Cust(string name, bool rob_shop, int arrival, int items)
{
   m_name = name;
   m_rob_shop = rob_shop;
   m_arrival = arrival;
   m_items = items;
}

bool Cust :: getRobber()
{
   return m_rob_shop;
}

string Cust :: getName()
{
   return m_name;
}

int Cust :: getItems()
{
   return m_items;
}

int Cust :: getArrival()
{
   return m_arrival;
}

int Cust :: getDone()
{
   return m_arrival + (m_items * 2);
}

int Cust :: getDone_checking(int clock)
{
   return clock + m_items;  
}

void Cust :: print(ostream &os)
{
   os << m_name << " ";
   if (m_rob_shop == true)
   {
      os << "robber ";
   }
   else
   {
      os << "shopper ";
   }
   os << m_arrival << " ";
   os << m_items << endl;
}

void Cust :: print_entered(ostream &os, int clock)
{
   assert(clock == m_arrival);
   os << clock << ": " << m_name << " entered store" << endl;
}

void Cust :: print_exit(ostream &os, int clock)
{
   os << clock << ": " << m_name << " exited store" << endl;
}

void Cust :: print_start_check(ostream &os, int clock, int checkerNum)
{
   os << clock << ": " << m_name << " started checkout with checker " << checkerNum << endl;
}

void Cust :: print_end_check(ostream &os, int clock, int checkerNum, int reg_money)
{
  if (m_rob_shop == false && m_items != 1)
  {
     os << clock << ": " << m_name << " paid $" << m_items * 3 << " for " << m_items << " items to checker " << checkerNum << endl;
  }
  
  if (m_rob_shop == false && m_items == 1)
  {
     os << clock << ": " << m_name << " paid $" << m_items * 3 << " for " << m_items << " item to checker " << checkerNum << endl;
  }
  
  if (m_rob_shop == true && m_items != 1)
  {
     os << clock << ": " << m_name << " stole $" << reg_money << " and " << m_items << " items from checker " << checkerNum << endl;
  }
  
  if (m_rob_shop == true && m_items == 1)
  {
     os << clock << ": " << m_name << " stole $" << reg_money << " and " << m_items << " item from checker " << checkerNum << endl;
  }
}

void Cust :: print_done_shop(ostream &os, int clock)
{
   os << clock << ": " << m_name << " done shopping" << endl;
}
