#include <iostream>
#include <string>
#include "vehicle.cpp"
#include "car.cpp"
#include "HondaCity.cpp"
#include "bus.cpp"
using namespace std;
int main()
{
   //HondaCity h(4,5);
   /*
   Vehicle v;
   v.color = "Blue";
   // Not Accessible
   // v.maxSpeed = 100;
   //  v.numTyres=4;
   Car c(5);
   c.color = "Black";
   //error numTyres 
  // c.numTyres = 4;
   
   c.numGears=5;
  */
  //=== Hybride
     Bus b;
     b.Car :: numGears=55;
     b.Car::color="Black";
     b.Car::print();
  //=====
  return 0;
}
