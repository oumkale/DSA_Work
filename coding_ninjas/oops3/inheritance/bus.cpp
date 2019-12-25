#include "vehicle.cpp"
#include <iostream>
#include "car.cpp"
#include "truck.cpp"
#pragma once 
using namespace std;
class Bus:public Car,public Truck
{
   public:
   Bus()
   {
     cout << "Bus's Contructor"<< endl;
   }
};
