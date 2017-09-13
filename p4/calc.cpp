include <iostream>
#include "dstack.h"
#include "stdio.h"
#include <cmath>
using namespace std;

void error()
{
  cerr << "Error: Invalid expression." << endl;
  exit(1);
}

void check(bool checking)
{
  if (checking == false)
  {
    error();
  }
}

int main()
{
  char operation;
  bool checking = true;
  double value = 0;
  double LHS = 0;
  double RHS = 0;
  double results = 0;
  Stack stack;
  checking = stack.pop(value);

  while (cin.peek() != EOF)
  {
    if((isdigit(cin.peek())) || (cin.peek() == '.'))
    {
      cin >> value;
      if(cin.peek() == '.')
      {
        error();
      }
      stack.push(value);
    }

    else if(isspace(cin.peek()))
    {
      cin.ignore();
    } 

    else
    {

      cin >> operation;

      if (operation == '*')
      {
        checking = stack.pop(value);
        check(checking);

        LHS = value;
        checking = stack.pop(value);
        check(checking);

        RHS = value;
        results = LHS * RHS;
        stack.push(results);
      }

      else if (operation == '+')
      { checking = stack.pop(value);
        check(checking);

        LHS = value;
        checking = stack.pop(value);
        check(checking);

        RHS = value;
        results = RHS + LHS;
        stack.push(results);
      }

      else if (operation == '-')
      {checking = stack.pop(value);
        check(checking);

        LHS = value;
        checking = stack.pop(value);
        check(checking);

        RHS = value;
        results = RHS - LHS;
        stack.push(results);
      }

      else if (operation == '/')
      {checking = stack.pop(value);
        check(checking);

        LHS = value;
        checking = stack.pop(value);
        check(checking);

        RHS = value; 
        results = RHS / LHS;
        if (results == 0)
        {
          error();
        }
        stack.push(results);
      }

      else if (operation == '^')
      {checking = stack.pop(value);
        check(checking);

        LHS = value;
        checking = stack.pop(value);
        check(checking);

        RHS = value;
        if (RHS == 0)
        {
          results = 1;
        }
        else
        {
          results = pow(RHS, LHS);
        }
        stack.push(results);
      }
    }
  } 

  if (stack.size() > 1)
  {
    error();
  }  

  stack.pop(value);
  cout << value << endl;

  return 0;

}
