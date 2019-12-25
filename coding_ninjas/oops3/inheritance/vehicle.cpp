#include <cstring>
#pragma once 
#include <iostream>
using namespace std;
class Vehicle
{
  private:
    int maxSpeed;
  protected:
    int numTyres;
  public:
    std::string color;   
   Vehicle()
    {
      cout << "Vehicle's Default Contructor" << endl;
    }
    
    Vehicle(int maxSpeed)
    {
        cout << "Vehicle's Parametrise Contructor" << endl;
        this ->maxSpeed = maxSpeed;
    }
    ~Vehicle()
    {
      cout << "Vehicle's Default Destructor" << endl;
    } 
};
