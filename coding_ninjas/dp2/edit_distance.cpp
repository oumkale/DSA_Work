#include <iostream>
#include <string>
using namespace std;
int main()
{
   string a,b;
   int m,n;
   cin>>a;
   cin>>b;
   int lcs_length = lcs(a,b);
   cout << "Longest Common Sequence Length by Brute Force is :"<< lcs_length<< endl; 
   m = a.size();
   n = b.size();
   int **output = new int*[m+1];
   for(int i=0;i<=m;i++)
   {
       output[i] = new int[n+1];
     
   }
   for(int i=0;i<=m;i++)
   {
     for(int j=0;j<=n;j++)
     {
         output[i][j] = -1;
     } 
   }
   int **out = output;
   int lcs_length_memo = lcs_memo(a,b,out);
   cout << "Longest Common Sequence Length by Memorisation is :"<< lcs_length_memo<< endl; 
    int lecs_len_dp = lcs_dp(a,b,out); 
   cout << "Longest Common Sequence Length by Dynamic Programming is :"<< lecs_len_dp<< endl;  
   return 0;
}
