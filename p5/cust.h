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
      void print_entered(ostream &os, int clock);
      void print_done_shop(ostream &os, int clock);
      void print_exit(ostream &os, int clock);
      void print_start_check(ostream &os, int clock, int checkerNum);
      void print_end_check(ostream &os, int clock, int checkerNum, int reg_money);
      int getArrival();
      int getItems();
      int getDone();
      int getDone_checking(int clock);
      string getName();
      bool getRobber();

   private:
      string m_name;
      bool m_rob_shop;
      int m_arrival;
      int m_items;
};
#endif
