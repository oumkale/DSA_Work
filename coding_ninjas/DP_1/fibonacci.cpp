#include <iostream>
using namespace std; 
class fibbonacci
{
     public:
      int fibbo3(int n)
      {
          int a[n+1];
          a[0]=0;
          a[1]=1;
          for(int i=2;i<=n;i++)
            a[i] = a[i-1] + a[i-2];
           return a[n]; 
      }
      // Normally o(2^n)
      
      int fibbo(int n)
      {
          if(n<=1)
            return n;
           
           int a = fibbo(n-1);
           int b = fibbo(n-2);
           
           return (a+b); 
      }
      // Using array O(n)
      
      int fibboHelper(int *ans,int n)
      {
          if(n<=1)
            return n;
          if(ans[n] != -1)
          {
             return ans[n];
          }  
           int a = fibboHelper(ans,n-1);
           int b = fibboHelper(ans,n-2);
           // save output for future use
            ans[n] = a+b;
            
            // return the final output
           return ans[n];    
      }
      
      int fibbo1(int n)
      {
          int *a = new int[n+1];
          for(int i=0;i<=n;i++)
          {
             a[i] = -1;
          }
          int l = fibboHelper(a,n);
          return l;
      }
      
};
int main()
{
   cout << "Fibonacci Series" << endl;
   fibbonacci fb;
   int ch,choice,l,m,n;
   do{
      cout <<"Which Method"<<endl;
      cout << "1.Normal Recursive O(2^n) Brute Force Simplest" << endl;
      cout << "2.Memorisation way O(n) using recursive " << endl; // saving answers
      cout << "3.Iterative way O(n) Dynamic Programming "<< endl; // Best becouse it takes less space 
      cout << "4.Is Empty" << endl;
      cout << "5.Remove Min" << endl;
      cout << "9.Enter Choice" << endl;
      cin >> ch;
      
      switch(ch)
      {
         case 1: 
             cout << "Enter Numer" << endl;
              cin>>n;
   
             l = fb.fibbo(n);
             cout << "Value is using Bruite Force:" << l << endl;
         break;
         case 2:
                 cout << "Enter Numer" << endl;
              cin>>n;
             l = fb.fibbo1(n);
             cout << "Value is using Memorisation Approach :" << l << endl;break;
         case 3:
              cout << "Enter Numer" << endl;
                cin>>n;
              l = fb.fibbo3(n);
             cout << "Value is using Dynamic Programming Approach :" << l << endl;break;
             
         break;
         default:  cout << "Please Enter Correct choice" << endl;
         break;
         
      }
      
   }while(ch!=-1);
}
