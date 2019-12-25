#pragma once 
#include <iostream>
using namespace std;
#include "Student.cpp"
#include "Teacher.cpp"
class TA:public Teacher,public Student
{
   public:
  
   void print()
   {
     cout << "TA"<< endl;
   }
   
};
