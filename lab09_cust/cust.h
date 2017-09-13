#include <iostream>
#include <string>
#ifndef CUST_H
#define CUST_H
using namespace std;
class Cust
{
  public:
  Cust(string name, bool rob_shop, int arrival, int items);
  void print(ostream &os);

  private:
  string m_name;
  bool m_rob_shop = true;
  int m_arrival;
  int m_items;
};
#endif
