#include <iostream>
using namespace std;
class Student
{
  public:
  int a;
  const int num;
  int &x;
  
  Student(int r,int a):num(r),a(a),x(a)
  {
    cout<<num<<" "<<a<<" "<<x<<endl;
  }
  
  
};
int main()
{
  Student s(3,5);
  s.a =20;
  cout<<s.num<<" "<<s.a<<" "<<s.x<<endl;
  return 0;
}
