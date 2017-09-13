#include "cust.h"
#include <iostream>
using namespace std;

Cust :: Cust(string name, bool rob_shop, int arrival, int items)
{
  m_name = name;
  m_rob_shop = rob_shop;
  m_arrival = arrival;
  m_items = items;
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
