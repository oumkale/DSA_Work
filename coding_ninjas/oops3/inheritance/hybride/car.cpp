#include "vehicle.cpp"
#include <iostream>
#pragma once 
using namespace std;
class Car : public Vehicle //publically 
{
  public:
    int numGears;
    Car()
    {
    
    }
    
    Car(int x):Vehicle(x)
    {
      cout << "Car's Parametric 1 Contructor" << endl;
    }
    Car(int x,int y):Vehicle(x,y)
    {
      cout << "Car's Parametric 2 Contructor" << endl;
    }
    ~Car()
    {
      cout << "Car's Destructor" << endl;
    }
    void print()
    {
      cout << "NumTyres :"<<numTyres<< endl;
      cout << "Color :"<<color<< endl;
      //cout << "Max Speed :"<<maxSpeed<< endl; 
      cout << "Num Gears :"<<numGears<< endl;
    }   
};

