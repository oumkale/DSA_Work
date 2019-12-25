#include "vehicle.cpp"
#include <iostream>
#pragma once 
using namespace std;
class Car : public Vehicle //publically 
{
class Bus:public Car,public Truck
{
   public:
   Bus()
   {
     cout << "Bus's Contructor"<< endl;
   }
};
