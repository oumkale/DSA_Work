#include <iostream>
#include <bits/stdc++.h>
#include <queue>
#include <vector>
using namespace std;
void k_sorted(int a[],int n,int k)
{
      priority_queue<int> pq;
      for(int i=0;i<k;i++)
      pq.push(a[i]);
      int j=0;
      
      for(int i=k;i<n;i++)
      {
        a[j] = pq.top();
        pq.pop();
        pq.push(a[i]);
        j++;
      }
      while(!pq.empty())
      {
         a[j]=pq.top();
          pq.pop();
         j++;
      }
      cout << "Array after k-sorted" << endl;
      for(int i=0;i<n;i++)
      {
         cout << a[i] << " " ;
         
      }
      cout << endl;
}
vector<int> kSmallest(int input[], int n, int k) {
	// Write your code here
    vector<int> v;
     priority_queue<int> pq;
    for(int i=0;i<k;i++)
    {
        pq.push(input[i]);
    }
    for(int i=k;i<n;i++)
    {
        if(input[i] < pq.top())
        {
             pq.pop();
            pq.push(input[i]);
        }
    }
    for(int i=0;i<k;i++)
    {
          v.push_back(pq.top());
          pq.pop();
    }
    return v;
}
vector<int> kLargest(int input[], int n, int k)
{
    // Write your code here
    vector<int> v;
     priority_queue<int,vector<int>,greater<int>> pq;
    for(int i=0;i<k;i++)
    {
        pq.push(input[i]);
    }
    for(int i=k;i<n;i++)
    {
        if(input[i] > pq.top())
        {
             pq.pop();
            pq.push(input[i]);
        }
    }
    for(int i=0;i<k;i++)
    {
          v.push_back(pq.top());
          pq.pop();
    }
    return v;
}
int main()
{
  int n,k,ch;
  int a[100];
   vector<int> vs;
   vector<int> vl; 
  cout << "Type length of Array and K Sorted Array " << endl;
  cin>>n>>k;
  cout << "Type Array " << endl;
  for(int i=0;i<n;i++)
  {
    cin >> a[i];
  }
  do{
      cout << "1. K sorted array " << endl;
      cout << "2. K min elements" << endl;
      cout << "3. K max elements" << endl;
      cout << "Type choice :";
      cin>>ch;
      switch(ch)
      {
        case 1:
           k_sorted(a,n,k);
        break;
        case 2:
           vs = kSmallest(a, n, k);
            cout << "K Smallest elements" << endl;
            for(int i=0;i<k;i++)
   			{
               cout << vs.at(i)<< " ";
    		}
    		cout << endl;
        break;
        case 3:
           vl = kLargest(a,n,k);
           cout << "K Largest elements" << endl;
            for(int i=0;i<k;i++)
   			{
               cout << vl.at(i)<< " ";
    		}
    		cout << endl;
        break;
        default:cout << "Apna time aayega" << endl;
        break;
      }
  }while(ch!=-1);
}
