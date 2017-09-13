#ifndef Tree_H
#define Tree_H
#include <iostream>
#include <vector>
#include <queue>
using namespace std;

class Tree
{

class Node;
   
   public:
      void print();
      bool insert (string str);
      bool lookup(string str);
      int height();
      int size();
      double distance();
      void insert_vector(vector<string>&strings);
      void bft();
      int balanced();
      void rebalance();

   private:
      class Node
      {

         public:
            ~Node() { delete m_left, delete m_right; }
            Node(string str) 
            { 
               m_str = str; 
               m_left = NULL;
               m_right = NULL;
            }

            string m_str;
            Node *m_left;
            Node *m_right;
      };
      
      void m_rebalance(vector<string>&strings, int start, int end);
      int m_balanced(Node *cur_node);
      void m_bft(queue<Node *>&q, vector<string>&v, Node *cur_node);
      void m_insert_vector(vector<string>&strings, Node *cur_node);
      void m_print(vector<string>&strings, Node *cur_node);
      int m_height(Node *cur_node);
      int m_size(Node *cur_node);
      double m_distance(double length, Node *cur_node, queue<Node *>&q);
      bool m_insert(string str, Node *&cur_node);
      bool m_lookup(string target, Node *cur_node);
      Node *m_root = NULL;

};
#endif
