#include <iostream>
using namespace std;
#include "Teacher.cpp"
#include "Student.cpp"
#include "TA.cpp"

int main()
{
   TA a;
   //a.Student::print();
   a.print();
   a.Student::print();
   a.Teacher::print();

}
