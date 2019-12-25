#include <iostream>
#include <bits/stdc++.h>
#include <cmath>
using namespace std;
int countstep(int n)
{
    if (n == 1) 
        return 0; 
     int a=INT_MAX, b=INT_MAX, c=INT_MAX;
    if (n % 2 == 0) 
        a = 1 + countstep(n / 2); 
    if (n % 3 == 0) 
         b = 1 + countstep(n / 3); 
    
         c = 1 + countstep(n - 1); 
     
     return min(min(a,b),c);                
                     
}
int countmemorisation(int n,int ar[])
{
    if(n<=1)
      return 0;
     if(ar[n] != -1)
       return ar[n]; 
       
    int a=INT_MAX, b=INT_MAX, c=INT_MAX;
    if (n % 2 == 0) 
        a = 1 + countstep(n / 2); 
    if (n % 3 == 0) 
         b = 1 + countstep(n / 3); 
    c = 1 + countstep(n - 1); 
     ar[n] =  min(min(a,b),c);
     return ar[n];  
}
int countmemo(int n)
{
    int * a = new int[n+1];
    for(int i=0;i<=n;i++)
      a[i] = -1;
      
      return countmemorisation(n,a);
    
}
int countmemo(int n)
{
   int *a = new int[n+1];
   a[0]=0;
   a[1]=0;
   
   for(int i=2;i<=n;i++)
   {
     a[]
   } 
}
//----------------------
#include <cmath>
int minCount(int n){
    
    /*  Don't write main().
     *  Don't read input, it is passed as function argument.
     *  Return output and don't print it.
     *  Taking input and printing output is handled automatically.
     */
   /* 
    // base cases 
    // if n is perfect square then Minimum squares required is 1 (144 = 12^2) 
    if (sqrt(n) - floor(sqrt(n)) == 0) 
        return 1; 
   if (n <= 3) 
        return n; // if (n <= 3) 
     //   return n;
    int res = n; // Maximum squares required is n (1*1 + 1*1 + ..) 
  
    // Go through all smaller numbers 
    // to recursively find minimum 
    for (int x = 1; x <= n; x++) { 
        int temp = x * x; 
        if (temp > n) 
            break; 
        else
            res = min(res, 1 + minCount(n - temp)); 
    } 
    return res; 
*/
      int* dp = new int[n + 1]; 
  
    // getMinSquares table for base case entries 
    dp[0] = 0; 
    dp[1] = 1; 
    dp[2] = 2; 
    dp[3] = 3; 
  
    // getMinSquares rest of the table using recursive 
    // formula 
    for (int i = 4; i <= n; i++) { 
        // max value is i as i can always be represented 
        // as 1*1 + 1*1 + ... 
        dp[i] = i; 
  
        // Go through all smaller numbers to 
        // to recursively find minimum 
        for (int x = 1; x <= ceil(sqrt(i)); x++) { 
            int temp = x * x; 
            if (temp > i) 
                break; 
            else
                dp[i] = min(dp[i], 1 + dp[i - temp]); 
        } 
    } 
  
    // Store result and free dp[] 
    int res = dp[n]; 
    delete[] dp; 
  
    return res; 
}

//------------------
long long int mod = 1000000007;
    
int balancedBTs(int h) { 
       
    long long int dp[h + 1]; 
    //base cases 
    dp[0] = dp[1] = 1; 
    for(int i = 2; i <= h; i++) { 
        dp[i] = (dp[i - 1] * ((2 * dp [i - 2])%mod + dp[i - 1])%mod) % mod; 
    } 
    return dp[h]; 
} 

int main()
{
   cout << "******* Min step to 1 Series **********" << endl;
   
   int ch,choice,l,m,n;
   do{
      cout <<"Which Method"<<endl;
      cout << "1.Normal Recursive O(2^n) Brute Force Simplest" << endl;
      cout << "2.Memorisation way O(n) using recursive " << endl; // saving answers
      cout << "3.Iterative way O(n) Dynamic Programming "<< endl; // Best becouse it takes less space 
      cout << "4.Min Count of sum of whose squares is equal to N " << endl;
      cout << "5.Number of BST possible if H is given" << endl;
      cout << "9.Enter Choice" << endl;
      cin >> ch;
      
      switch(ch)
      {
         case 1: 
             cout << "Enter Numer :" << endl;
              cin>>n;
   
             l = countstep(n);
             cout << "Count is using Bruite Force:" << l << endl;
         break;
         case 2:
                 cout << "Enter Numer :" << endl;
              cin>>n;
             l = countmemo(n);
             cout << "Count is using Memorisation Approach :" << l << endl;break;
         case 3:
              cout << "Enter Numer :" << endl;
                cin>>n;
              
            cout << "Count is using Dynamic Programming Approach :" << l << endl;break;
             
         break;
         case 4:
           cout << "Enter Numer :" << endl;
              cin>>n;
             l = minCount(n);
             cout << "Min Count of sum of whose squares is equal to N " << l <<endl;
         break;
         case 5;
           cout << "Enter Height :" << endl;
              cin>>n;
             l = balancedBTs(n);
             cout << "Min BST possible if H is given is :" << l <<endl;
         break;
         default:  cout << "Please Enter Correct choice" << endl;
         break;
         
      }
      
   }while(ch!=-1);
}
:
