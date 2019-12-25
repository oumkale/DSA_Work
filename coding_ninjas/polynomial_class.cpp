#include <iostream>
#include <bits/stdc++.h>
using namespace std;

class Polynomial {
    public:
    int *degCoeff;      // Name of your array (Don't change this)
    int capacity;
    // Complete the class
    
    Polynomial()
    {
        degCoeff =new int[10];
        capacity = 10;
        for(int i=0;i<capacity;i++)
        {
           degCoeff[i] = 0;
        }         
        
    }
   Polynomial(Polynomial const &p) 
   {
     degCoeff = new int[p.capacity];
     for(int i = 0; i < p.capacity; i++) 
     {
       degCoeff[i] = p.degCoeff[i];
     }  
    capacity = p.capacity;
   }
   void operator=(Polynomial const &p) 
   {
     delete [] degCoeff;
     degCoeff = new int[p.capacity];
     for(int i = 0; i < p.capacity; i++) 
     {
       degCoeff[i] = p.degCoeff[i];   
     }
     capacity = p.capacity;
   }
    void setCoefficient(int degree, int coeff)
    {
       if(degree >= capacity) 
       {
		int size = 2 * capacity;
		while(size <= degree) 
		{
			size *= 2;
		}
		int *newDegCoeff = new int[size];
		for (int i = 0; i < size; i++) 
		{
			newDegCoeff[i] = 0;
		}
		for(int i = 0; i < capacity; i++) 
		{
			newDegCoeff[i] = degCoeff[i];
		}
		capacity = size;
		delete [] degCoeff;
		degCoeff = newDegCoeff;
	  }
		degCoeff[degree] = coeff;
}
      void print()
      {
          for(int i = 0; i < capacity; i++) 
          {
            if(degCoeff[i] != 0) 
            {
              cout << degCoeff[i] << "x" << i << " ";
            }
          }
         cout << endl;
      }
    
    
	Polynomial operator+(Polynomial const &p)
	{
		Polynomial pNew;
		int i = 0, j = 0;
		while(i < this -> capacity && j < p.capacity) 
		{
			int deg = i;
			int coeff = this -> degCoeff[i] + p.degCoeff[j];
			pNew.setCoefficient(deg, coeff);
			i++;
			j++;
        }
		while(i < capacity) 
		{
      	    pNew.setCoefficient(i, degCoeff[i]);
            i++;
        }
		while(j < p.capacity) 
		{
			pNew.setCoefficient(j, p.degCoeff[j]);
			j++;
        }
		return pNew;
     }
    
    // Minus
    /* Polynomial  operator-(Polynomial const &d)
    {
         int capacity1;
         if(this->capacity > d.capacity)
            capacity1 = this->capacity;
         else
            capacity1 = d.capacity;   
         
         
         int *degCoeff1 = new int[capacity1];
         for(int i=0;i<capacity1;i++)
         {
            degCoeff1[i] = 0;
         }
         int deg1,deg2,cap1,cap2;
         for(int i=0;i<capacity1;i++)
         {
           // cout<<this->degCoeff[i]<<" "<<d.degCoeff[i]<<endl;
            if((this->degCoeff[i])!=0 && d.degCoeff[i]!=0)
            {
             cap1 = this->degCoeff[i];
             cap2 =  d.degCoeff[i];
             deg1 = i;
             degCoeff1[i] = cap1 - cap2;
            }
            else if(this->degCoeff[i]!=0)
            {
             cap1 = this->degCoeff[i];
             degCoeff1[i] = cap1; 
            }
            else if(d.degCoeff[i]!=0)
            {
              cap2 = d.degCoeff[i];
              degCoeff1[i] = cap2;
            }
         }
         Polynomial fnew;
         fnew.degCoeff = degCoeff1;
         fnew.capacity = capacity1;
         delete [] degCoeff1;
         return fnew;
    }
    */
    Polynomial operator-(Polynomial const &p)
	{
		Polynomial pNew;
		int i = 0, j = 0;
		while(i < this -> capacity && j < p.capacity) 
		{
			int deg = i;
			int coeff = this -> degCoeff[i] - p.degCoeff[j];
			pNew.setCoefficient(deg, coeff);
			i++;
			j++;
        }
		while(i < capacity) 
		{
      	    pNew.setCoefficient(i, degCoeff[i]);
            i++;
        }
		while(j < p.capacity) 
		{
			pNew.setCoefficient(j,(-1) * p.degCoeff[j]);
			j++;
        }
		return pNew;
     }
     int getCoefficient(int degree) 
     {
		if (degree >= capacity) 
		{
			return 0;
		}
        return degCoeff[degree];
      }
   /* Polynomial  operator*(Polynomial const &d)
    {
         int capacity1;
         if(this->capacity > d.capacity)
            capacity1 = this->capacity;
         else
            capacity1 = d.capacity;   
         int *degCoeff1 = new int[capacity1];
         for(int i=0;i<capacity1;i++)
         {
            degCoeff1[i] = 0;
         }
         int deg1,deg2,cap1,cap2;
         for(int i=0;i<capacity1;i++)
         {
           // cout<<this->degCoeff[i]<<" "<<d.degCoeff[i]<<endl;
            if((this->degCoeff[i])!=0 && d.degCoeff[i]!=0)
            {
             cap1 = this->degCoeff[i];
             cap2 =  d.degCoeff[i];
             deg1 = i;
             degCoeff1[i] = cap1 * cap2;
            }
            else if(this->degCoeff[i]!=0)
            {
             cap1 = this->degCoeff[i];
             degCoeff1[i] = cap1; 
            }
            else if(d.degCoeff[i]!=0)
            {
              cap2 = d.degCoeff[i];
              degCoeff1[i] = cap2;
            }
         }
         Polynomial fnew;
         fnew.degCoeff = degCoeff1;
         fnew.capacity = capacity1;
         delete [] degCoeff1;
         return fnew;
    }
    */
    Polynomial operator*(Polynomial p)
    {
	   Polynomial pNew;
	   for(int j = 0; j < p.capacity; j++) 
	   {
		for(int i = 0; i < capacity; i++) 
		{
			int deg = i + j;
			int coeff = pNew.getCoefficient(deg) + (this -> degCoeff[i] *p.degCoeff[j]);
		pNew.setCoefficient(deg, coeff);
		}
       }
	return pNew;
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
    cin >> count2;
    
    int *degree2 = new int[count2];
    int *coeff2 = new int[count2];
    
    for(int i=0;i < count2; i++) {
        cin >> degree2[i];
    }
    
    for(int i=0;i < count2; i++) {
        cin >> coeff2[i];
    }
    
    Polynomial second;
    for(int i = 0; i < count2; i++){
        second.setCoefficient(degree2,i,coeff2,i);
    }
    second.print();
    
    cin >> choice;
    
    Polynomial result;
    switch(choice)
    {
            // Add
        case 1:
            result = first + second;
            result.print();
            break;
            // Subtract
        case 2 :
            result = first - second;
            result.print();
            break;
            // Multiply
        case 3 :
            result = first * second;
            result.print();
            break;
            
       case 4 : // Copy constructor
        {
            Polynomial third(first);
            if(third.degCoeff == first.degCoeff) {
                cout << "false" << endl;
            }
            else {
                cout << "true" << endl;
            }
            break;
        }
            
        case 5 : // Copy assignment operator
        {
            Polynomial fourth(first);
            if(fourth.degCoeff == first.degCoeff) {
                cout << "false" << endl;
            }
            else {
                cout << "true" << endl;
            }
            break;
        }
        
            
    }
    
    
    return 0;
}
Looking forward to your response.


