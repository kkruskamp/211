#include "bst.h"
#include <iostream>
using namespace std;

//INSERT
bool Tree :: m_insert (string str, Node *&cur_node)
{  

   if (cur_node == NULL)
   {
      cur_node = new Node(str);
      return true;
   }

   if (cur_node->m_str == str)
   {
      return false;
   }

   if (str < cur_node->m_str)
   {
      return m_insert(str, cur_node->m_left);
   }

   else
   {
      return m_insert(str, cur_node->m_right);
   }  

}

bool Tree :: insert(string str)
{
   return m_insert(str, m_root);
}

//INSERT INTO VECTOR
void Tree :: m_insert_vector(vector<string>&strings, Node *cur_node)
{

   if (cur_node == NULL)
   {
      return;
   }

   m_insert_vector(strings, cur_node->m_left);

   strings.push_back(cur_node->m_str);

   m_insert_vector(strings, cur_node->m_right);

}

void Tree :: insert_vector(vector<string>&strings)
{
   m_insert_vector(strings, m_root);
}

//PRINT

void Tree :: m_print(vector<string>&strings, Node *cur_node)
{
   cout << "{";

   for (unsigned int i = 0; i < strings.size(); i++)
   {
      cout << strings[i];

      if (i < strings.size() - 1)
      {
         cout << ", ";
      }
      else
      {
         cout << "}" << endl;
      }
   }
}

void Tree :: print()
{
   vector<string>strings;
   insert_vector(strings);
   m_print(strings, m_root);
}

//LOOKUP
bool Tree :: m_lookup(string str, Node *cur_node)
{
   if (cur_node == NULL)
   {
      return false;
   }  

   if (cur_node->m_str == str)
   {
      return true;
   }

   if (str < cur_node->m_str)
   {
      return m_lookup(str, cur_node->m_left);
   }

   else
   {
      return m_lookup(str, cur_node->m_right);
   }
}

bool Tree :: lookup(string str)
{
   return m_lookup(str, m_root);
}

//HEIGHT
/*int Tree :: m_height(Node *cur_node)
{
   if (cur_node == NULL)
   {
      return 0;
   }
   int left = m_height(cur_node->m_left);
   int right = m_height(cur_node->m_right);
   return 1 + max(left, right);
}

int Tree :: height()
{
   return m_height(m_root);
}
*/

//SIZE
int Tree :: m_size(Node *cur_node)
{
   if (cur_node == NULL)
   {
      return 0;
   }

   int left = m_size(cur_node->m_left);
   int right = m_size(cur_node->m_right);
   
   return 1 + left + right;
}

int Tree :: size()
{
   return m_size(m_root);
}

//DISTANCE
double Tree :: m_distance(double length, Node *cur_node, queue<Node *>&q)
{
   //CUR ROOT DOESNT CHANGE
   Node *cur_root = q.front();

   if (cur_node == NULL || cur_node->m_str == cur_root->m_str)
   {
      q.pop();
      return length;
   }
   else
   {
      if (cur_node->m_str < cur_root->m_str)
      {
         return m_distance(length + 1, cur_node->m_right, q);
      }
      else
      {
         return m_distance(length + 1, cur_node->m_left, q);
      }
   }
}

double Tree :: distance()
{
   double dist = 0;
   queue<Node *> q;
   q.push(m_root);
   while(!q.empty())
   {

      if(q.front()->m_left)
      {
         q.push(q.front()->m_left);
      }

      if(q.front()->m_right)
      {
         q.push(q.front()->m_right);
      }

      dist += m_distance(0, m_root, q);
   
   }
   
   cout << "Average distance of nodes to root = ";
   
   return dist / size();
}

//BREADTH
void Tree :: m_bft(queue<Node *>&q, vector<string>&v, Node *cur_node)
{
   if (cur_node == NULL)
   {
      return;
   }

   q.push(cur_node);

   while(!q.empty())
   {
      cur_node = q.front();

      if (cur_node->m_left)
      {
         q.push(cur_node->m_left);
      }
      if (cur_node->m_right)
      {
         q.push(cur_node->m_right);
      }
      
      //INFINITE LOOP
      q.pop();
      v.push_back(cur_node->m_str);

   }
}      

void Tree::bft()
{
   queue<Node *>q;
   vector<string>v;
   m_bft(q, v, m_root);
   m_print(v, m_root);
}

//BALANCED

int Tree :: m_balanced(Node *cur_node)
{
   if (cur_node == NULL)
   {
      return true;
   }

   int left = m_balanced(cur_node->m_left);
   int right = m_balanced(cur_node->m_right);

   if (left == -1 || right == -1)
   {
      return -1;
   }

   if(abs(left - right) > 1)
   {
      return -1;
   }
   else
   {
      //HEIGHT FUNCTION DIDNT WORK FUCK
      return 1 + max(left, right);
   }
}


int Tree :: balanced()
{
   if (m_balanced(m_root) != -1)
   {
      cout << "Tree is balanced." << endl;
      return 1;
   }
   else
   {
      cout << "Tree is not balanced." << endl;
      return 0;
   }
}

//REBALANCE

void Tree :: m_rebalance(vector<string>&strings, int start, int end)
{
   if (start <= end)
   {
      int middle = (start + end) / 2;
      insert(strings[middle]);
      m_rebalance(strings, start, middle -1);
      m_rebalance(strings, middle + 1, end);
   }
}

void Tree :: rebalance()
{
   vector<string>strings;
   insert_vector(strings);
   delete m_root;
   m_root = NULL;
   m_rebalance(strings, 0, strings.size() - 1);
}
