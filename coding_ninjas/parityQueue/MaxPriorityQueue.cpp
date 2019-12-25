#include <iostream>
#include <bits/stdc++.h>
#include<vector>
using namespace std;
class PriorityQueue {
    std::vector<int> v;
   public:
    int getMax()
    {
      if(isEmpty())
      {
         return 0;
      }
      return v[0];
    }
    bool isEmpty()
    {
       return v.size()==0;
    }
    int getSize()
    {
       return v.size();
    }
    int removeMax()
    {
      if(isEmpty())
        return 0;
      int ans=v[0];
      v[0] = v[v.size()-1];
      v.pop_back();
      
      int pI=0;
      int cI1 = pI * 2 + 1;
      int cI2 = pI * 2 + 2;
      int maxI = 0;
      while(cI1 < v.size())
      {
         if(v[maxI] < v[cI1])
         {
            maxI = cI1;
         }
         if(v[maxI] < v[cI2] && cI2 < v.size())
         {
            maxI = cI2;
         }
         if(pI == maxI)
           break;
          int temp = v[maxI];
          v[maxI] = v[pI];
          v[pI] = temp;
          
         pI = maxI; 
         cI1 = pI * 2 + 1;
         cI2 = pI * 2 + 2; 
      }
      return ans;
    }
    void print()
    {
      cout << "List :" << endl;
      for(int i=0;i<v.size();i++)
      {
        cout << v[i] << endl; 
      }
    }
    void insert(int element)
    {
       v.push_back(element);
       int cI = v.size()-1;
       
       
       while(cI > 0)
       {
          int pI = (cI-1)/2;   
          if(v[pI] < v[cI])
          {
              int temp = v[cI];
              v[cI] = v[pI];
              v[pI] = temp;
          }
          else
            break;
          cI = pI;
       } 
    }
};
int main() {
    PriorityQueue pq;
    int choice;
    
     do{
        cout << "Enter Choice :1 for Insert" << endl;
        cout << "Enter Choice :2 for get max" << endl;
        cout << "Enter Choice :3 for remove Max" << endl;
        cout << "Enter Choice :4 for size" << endl;
        cout << "Enter Choice :5 for is empty" << en
￼Following
dl;
        cout << "Enter Choice : " ;
        cin >> choice;
        switch(choice) {
            case 1 : // insert
                int element;
                cout << "Enter number to insert:" << endl;
                cin >> element;
                pq.insert(element);
                break;
            case 2 : // getMax
                 cout << "Max :" << endl;
                cout << pq.getMax() << endl;
                break;
            case 3 : // removeMax
                cout << "Remove Max :" << endl;
                cout << pq.removeMax() << endl;
                break;
            case 4 : // size
                cout << "Size :" << endl;
                cout << pq.getSize() << endl;
                break;
            case 5 : // isEmpty
                if(pq.isEmpty()) {
                    cout << "true" << endl;
                }
                else {
                    cout << "false" << endl;
                }
            case 6:
                 {
                   pq.print();
                 } 
            default :
                ;
        }
    }while(choice != -1);
}


