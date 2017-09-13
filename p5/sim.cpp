//kkruskamp
//Kruskamp, Kyle
//Kwik-e-Mart

#include <iostream>
#include <string>
#include <fstream>
#include <ctype.h>
#include <stdlib.h>
#include "cust.h"
#include "pqueue.h"
using namespace std;

//CHECKER/////////////////////////////////////////////////////////////////////////////////////////////

struct Checker
{
   Cust *m_cust = NULL;
   int m_money = 100;
   int time_avail = 0;
};

//FUNCTION DECLARATIONS//////////////////////////////////////////////////////////////////////////////////////////f///

bool legal_int(char *str);
void run_simulation(Pqueue &arrival_q, int num_checkers, int checker_break, ostream &my_ofile);

//MAIN///////////////////////////////////////////////////////////////////////////////////////////u//

int main(int argc, char *argv[])
{
   string  name;
   string  role_string;
   int arrival_time;
   int item_number;
   int num_custs;
   Pqueue arrival_q;

   if (argc != 5)
   {
      cerr << "Error: invalid number of command line arguments." << endl;
      return 1;
   }

   int num_checkers = atoi(argv[1]);
   int checker_break = atoi(argv[2]);
   ifstream my_ifile(argv[3], ios::in);
   ofstream my_ofile(argv[4], ios::out);

   if (legal_int(argv[1]) == false)
   {
      cerr << "Error: invalid number of checkers specified." << endl;
      return 1;
   }
   if (num_checkers <= 0)
   {
      cerr << "Error: invalid number of checkers specified." << endl;
      return 1; 
   }
   if (legal_int(argv[2]) == false)
   {
      cerr << "Error: invalid checker break duration specified." << endl;
      return 1;
   }
   if (checker_break < 0)
   {
      cerr << "Error: invalid checker break duration specified." << endl;
      return 1;
   }
   if (!my_ifile)
   { 
      cerr << "Error: could not open input file <" << argv[3] << ">." << endl;
      return 1;
   }
   if (!my_ofile)
   {
      cerr << "Error: could not open output file <" << argv[4] << ">." << endl;
      return 1;
   }


   while (my_ifile >> name)
   {
      my_ifile >> role_string;
      my_ifile >> arrival_time;
      my_ifile >> item_number;
      arrival_q.enqueue(new Cust(name, (role_string == "robber" ? true : false), arrival_time, item_number), arrival_time);
      num_custs++;
   }

   run_simulation(arrival_q, num_checkers, checker_break, my_ofile);

   return 0;
}

//RUN SIM/////////////////////////////////////////////////////////////////////////////////////////c//

void run_simulation(Pqueue &arrival_q, int num_checkers, int checker_break, ostream &my_ofile)
{
   int num_custs = arrival_q.size();
   int clock;
   Pqueue shopping_q;
   Pqueue checker_q;
   Checker *checkers = new Checker[num_checkers];

   for (clock = 1; num_custs > 0; clock++)
   {  
      while (arrival_q.getArrival() == clock)
      {
         Cust* cust = arrival_q.dequeue();
         cust->print_entered(my_ofile, clock);
         shopping_q.enqueue(cust, cust->getDone());
      }

      while (shopping_q.getArrival() == clock)
      {
         Cust* cust = shopping_q.dequeue();
         cust->print_done_shop(my_ofile, clock);
         checker_q.enqueue(cust, 1);
      }

      for(int i = 0; i < num_checkers; i++)
      { 
         if (checkers[i].m_cust != NULL && checkers[i].time_avail <= clock && checkers[i].m_cust->getRobber() == true)
         {
            checkers[i].m_cust->print_end_check(my_ofile, clock, i, checkers[i].m_money);
            checkers[i].m_money = 0;
            checkers[i].time_avail = clock + checker_break;
            delete checkers[i].m_cust;
            num_custs--;
            checkers[i].m_cust = NULL;
         }

         if (checkers[i].m_cust != NULL && checkers[i].time_avail <= clock && checkers[i].m_cust->getRobber() == false)
         {
            checkers[i].m_cust->print_end_check(my_ofile, clock, i, checkers[i].m_money);
            delete checkers[i].m_cust;
            num_custs--;
            checkers[i].m_cust = NULL;
         }
      }

      for (int i = 0; i < num_checkers && checker_q.empty() == false; i++)
      {
         if (checkers[i].m_cust == NULL && checkers[i].time_avail <= clock)
         {  
            checkers[i].m_cust = checker_q.dequeue();
            checkers[i].m_cust->print_start_check(my_ofile, clock, i);


            if(checkers[i].m_cust->getRobber() == false)
            {
               checkers[i].m_money += checkers[i].m_cust->getItems() * 3;
               checkers[i].time_avail = clock + checkers[i].m_cust->getItems();
            }


            if(checkers[i].m_cust->getRobber() == true)
            {
               checkers[i].time_avail = clock + 4;
            }

         }

      }  
   }

   for (int i = 0; i < num_checkers; i++)
   {
      my_ofile << "registers[" << i << "] = $" << checkers[i].m_money << endl;
   }

   my_ofile << "time = " << clock << endl;
}

//LEGAL INT////////////////////////////////////////////////////////////////////////////////////k//

bool legal_int(char *str)
{
   while(*str != 0)
   {
      if (!isdigit(*str))
      {
         return false;
      }
      str++;
   }
   return true;
}

///////////////////////////////////////////////////////////////////////////////////////!//

