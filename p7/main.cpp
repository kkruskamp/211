//BINARY SEARCH TREE
//Kkruskamp, Kyle
//kkruskamp

#include <iostream>
#include <vector>
#include "bst.h"
using namespace std;

int main()
{
   
   Tree tree;
   string arg;
   string command;
   while (cin >> command)
   {

      if (command == "echo")
      {
         cin.ignore();
         getline(cin, arg);
         cout << arg << endl;
      }

      else if (command == "insert")
      {
         cin.ignore();
         getline(cin, arg);
         if (tree.insert(arg) == false)
         {
            cerr << "insert <" << arg << "> failed. String already in tree." << endl;
         }
         else
         {
            tree.insert(arg);
         }
      }

      else if (command == "size")
      {
         cout << tree.size() << endl;
      }

      else if (command == "find")
      {
         cin >> arg;
         if (tree.lookup(arg) == true)
         {
            cout << "<" << arg << "> is in tree." << endl;
         }
         else
         {
            cout << "<" << arg << "> is not in tree." << endl;
         }
      }

      else if (command == "print")
      {
         tree.print();
      }

      else if (command == "breadth")
      {
         tree.bft();    
      }

      else if (command == "distance")
      {
         cout << tree.distance() << endl;
      }

      else if (command == "balanced")
      {
        tree.balanced();
      }

      else if (command == "rebalance")
      {
         tree.rebalance();
      }

      else
      {
         cerr << "Illegal command <" << command << ">." << endl;
         getline(cin, command);
      }
   }

   return 0;
}
