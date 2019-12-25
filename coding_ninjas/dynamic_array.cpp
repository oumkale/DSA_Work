#include <iostream>
#include <bits/stdc++.h>
using namespace std;

class Polynomial {
    int *degCoeff;      // Name of your array (Don't change this)
    int capacity;
    // Complete the class
    public:
    Polynomial()
    {
        degCoeff =new int[10];
        capacity = 10;
        for(int i=0;i<capacity;i++)
        {
           degCoeff[i] = 0;
        }         
        
    }
    
    
    void print()
    {
            for(int i=0;i<capacity;i++)
            {
                cout<<degCoeff[i]<<" ";
            }
            cout<<endl;
    }
    /*
      if(degree1 < capacity)
        {
            for(int i=0;i<capacity;i++)
            {
                defCoegff[degree1[i]] = coeff1[i];
            }
        }
    */
    void setCoefficient(int  degree1[],int n, int coeff1[],int m)
    {
        if(degree1[n] < capacity)
        {
                degCoeff[degree1[n]] += coeff1[m];
        }
        else
        {
            int *degCoeff1 = new int[2*capacity];
            for(int i=0;i<capacity;i++)
                degCoeff1[i] = degCoeff[i];
            for(int i=capacity;i<2*capacity;i++)
                degCoeff1[i] = 0;
            
            delete [] degCoeff;
            degCoeff = degCoeff1;
                delete [] degCoeff1;
            capacity *= 2;
            
           degCoeff[degree1[n]] = coeff1[m]; 
        }
    }
};

int main()
{
    int count1,count2,choice;
    cin >> count1;
    
    int *degree1 = new int[count1];
    int *coeff1 = new int[count1];
    
    for(int i=0;i < count1; i++) {
        cin >> degree1[i];
    }
    
    for(int i=0;i < count1; i++) {
        cin >> coeff1[i];
    }
    
    Polynomial first;
    
   for(int i = 0; i < count1; i++){
        first.setCoefficient(degree1,i,coeff1,i);
    }
    first.print();
    
    return 0;
}

