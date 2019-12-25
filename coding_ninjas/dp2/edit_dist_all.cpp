#include <iostream>
#include <vector>
using namespace std;
//Brute Force
int editDistance(string a, string b){

  /*  Don't write main().
   *  Don't read input, it is passed as function argument.
   *  Return output and don't print it.
   *  Taking input and printing output is handled automatically.
   */
    if(a.size() ==0 || b.size()==0)
         return max(a.size(), b.size());
     if(a[0] == b[0])
        return  editDistance(a.substr(1),b.substr(1));
     else
     {
         //write your code here
       int x,y,z;
       x = 1 + editDistance(a.substr(1),b);
       y = 1 + editDistance(a,b.substr(1));
       z = 1 + editDistance(a.substr(1),b.substr(1));
       int m = min(x,min(y,z));
       return m;
     }
         
}
//Memoisation

int helper(string s1, string s2, int **a){
int m=s1.size(),n=s2.size();
if(m<=0||n<=0){
return max(m,n);
}
if(a[m][n]!=-1)
return a[m][n];
else{
if(s1[0]==s2[0]){
int x=helper(s1.substr(1),s2.substr(1),a);
a[m-1][n-1]=x;
a[m][n]=x;
}
else{
a[m][n-1]=helper(s1,s2.substr(1),a);
a[m-1][n-1]=helper(s1.substr(1),s2.substr(1),a);
a[m-1][n]=helper(s1.substr(1),s2,a);
a[m][n]=min(a[m][n-1],min(a[m-1][n-1],a[m-1][n]))+1;
}
}
return a[m][n];
}
int editDistance_mem(string s1, string s2){
int m=s1.size()+1,n=s2.size()+1;
int **ans = new int*[m];
for(int i = 0; i < m; i++) {
ans[i] = new int[n];
for(int j = 0; j < n; j++) {
ans[i][j] = -1;
}
}
return helper(s1,s2,ans);
}    
int editDistance_dp(string a, string b, int **output)
{
        // first column need i
        int m = a.size();
        int n = b.size();
       for(int i=0;i<=m;i++)
       {
         output[i][0] = i;
       }
       // first row need i
       for(int i=0;i<=n;i++)
       {
         output[0][i] = i;
       }
       
       for(int i=1;i<=m;i++)
       {
          for(int j=1;j<=n;j++)
          {   
             if(a[m-i] == b[n-j])
             {
               output[i][j] = output[i-1][j-1]; 
             }
             else
             {
               int x = output[i-1][j];
               int y = output[i][j-1];
               int z = output[i-1][j-1];
               int mi = min(x, min(y,z));
               output[i][j] = mi + 1;
             }
          }
       }
       
      return output[m][n];
}
int main()
{
   string a,b;
   int m,n;
   cin>>a;
   cin>>b;
   int dir_d_length = editDistance(a,b);
   cout << "Edit Distance Length by Brute Force is :"<< dir_d_length<< endl; 
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
   int dir_d_length_memo = editDistance_mem(a,b);
   cout << "Edit Distance Length by Memoization is :"<< dir_d_length_memo<< endl; 
    int lecs_len_dp = editDistance_dp(a,b,output); 
   cout << "Edit Distance Length by Dynamic Programming is :"<< lecs_len_dp<< endl;  
   return 0;
}
