#include <iostream>
#include "PriorityQueue.h"
using namespace std; 
int main()
{
   PriorityQueue p;
   int ch,choice,l,m;
   do{
      cout << "Parity Queue" << endl;
      cout << "1.Insert" << endl;
      cout << "2.Get Size" << endl;
      cout << "3.Get Min"<< endl;
      cout << "4.Is Empty" << endl;
      cout << "5.Remove Min" << endl;
      cout << "9.Enter Choice" << endl;
      cin >> ch;
      switch(ch)
      {
         case 1: 
           cout << "Enter elements to be inserted (-1 to exit)" << endl;
            cin >> l;
            while(l!=-1)
            {
               p.insert(l);
               cin>>l;
            } 
         break;
         case 2:
            cout<< "Size : "<<p.getSize()<< endl;
         break;
         case 3:
            cout<< "Min : "<<p.getMin()<< endl;
         
         break;
         case 4:
             cout<< "Is Empty (1-Yes/0-No) : "<<p.isEmpty()<< endl;
         
         break;
         case 5:
               cout<<p.removeMin()<< endl;
         
         break;
         default:  cout << "Please Enter Correct choice" << endl;
         break;
         
      }
      
   }while(ch!=-1);
}
