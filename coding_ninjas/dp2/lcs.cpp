#include <iostream>
#include <string>
using namespace std;
int lcs_dp(string a, string b, int **out)
{
    int m = a.size();
    int n = b.size();
    // 0th row and column is 0
    for(int i=0;i<=n;i++)
      out[0][i] =0;
    for(int i=0;i<=m;i++)
      out[i][0] =0;  
    int x,y,z;
    for(int i=1;i<=m;i++)
    {
      for(int j=1;j<=n;j++)
      {
      
         if(a[m-i] == b[n-j])
           out[i][j] = 1 + out[i-1][j-1];
         else
         {
            x = out[i][j-1];
            y = out[i-1][j];
            z = out[i-1][j-1];
            out[i][j] = max(x,max(y,z)); 
         }  
      }
    }
    
    return out[m][n];
}
int lcs_memo(string a, string b,int **output)
{
   if(a.size() == 0 || b.size()==0)
     return 0;
     int m = a.size();
     int n = b.size();
   if(output[m][n] != -1)
      return output[m][n];  
     int l,x,y,z;
   if(a[0] == b[0])
    return 1 + lcs_memo(a.substr(1),b.substr(1),output);
   else
   {
     x = lcs_memo(a.substr(1),b,output);
     y = lcs_memo(a,b.substr(1),output);
     z = lcs_memo(a.substr(1),b.substr(1),output); // Not require coz it i slready covered
      l = max(x,max(y,z));
     
   }
   output[m][n] = l;
   return l;
}
int lcs(string a, string b)
{
   if(a.size() == 0 || b.size()==0)
     return 0;
     int l,x,y,z;
   if(a[0] == b[0])
    return 1 + lcs(a.substr(1),b.substr(1));
   else
   {
     x = lcs(a.substr(1),b);
     y = lcs(a,b.substr(1));
     z = lcs(a.substr(1),b.substr(1)); // Not require coz it i slready covered
     l = max(x,max(y,z));
     
   return l;
   }
}
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
