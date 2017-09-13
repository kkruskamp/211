#ifndef COURSE_H
#define COURSE_H
#include <iostream>
using namespace std;

class Course
{

  private:
  string m_dept;
  int m_number;
  int m_time;

  public:
  Course (string dept, int number, int time);
  void print();

};
#endif
