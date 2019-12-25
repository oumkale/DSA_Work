#include "vehicle.cpp"
#include <iostream>
#pragma once 
using namespace std;
class Truck : public Vehicle //publically 
{
  public:
    int numGears;
    //Car():Vehicle(x)
    Truck()
    {
      cout << "Truck's Default COntructor" << endl;
    }
    Truck(int x):Vehicle(x)
    {
      cout << "Truck's Parametric 1 Contructor" << endl;
    }
    Truck(int x,int y):Vehicle(x)
    {
      cout << "Truck's Parametric 2 Contructor" << endl;
    }
    ~Truck()
    {
      cout << "Truck's Destructor" << endl;
    }
    void print()
    {
      cout << "NumTyres :"<<numTyres<< endl;
      cout << "Color :"<<color<< endl;
      //cout << "Max Speed :"<<maxSpeed<< endl; 
      cout << "Num Gears :"<<numGears<< endl;
    }   
};

