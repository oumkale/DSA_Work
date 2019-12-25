#include <iostream>

using namespace std;
int knapsack(int* weights, int* values, int n, int maxWeight)
{
    int a,b,w=0,va=0;
    if(n == 0 || maxWeight == 0)
        return 0;
    if(weights[0] > maxWeight)
        return knapsack(weights+1,values+1,n-1,maxWeight);
     a = knapsack(weights+1,values+1,n-1,maxWeight-weights[0]) + values[0];
     b = knapsack(weights+1,values+1,n-1,maxWeight);
   return max(a,b);
}

int main()
{
   int n;
   cout << "Enter : length "<< endl;
   cin>>n;
   int a[n];
   int b[n];
    cout << "Enter weights ans values :"<< endl;
    for(int i=0;i<n;i++)
    {
       cin>>a[i];
       cin>>b[i];
    }
    int v,w;
    cout << "Max Weight : " << endl;
    cin>>w;
     
   int knapsack_bf = knapsack(a,b,n,w);
   cout << "knapsack Length by Brute Force is :"<< knapsack_bf<< endl; 
  /*
   int knapsack_mem = knapsackmem(a,b,n,w);
   cout << "knapsack Length by Memoization is :"<< knapsack_mem<< endl; 
   int knapsack_dp = knapsackdp(a,b,n,w);
   cout << "knapsack Length by Dynamic Programming is :"<< knapsack_dp<< endl;
   */
   return 0;
}
