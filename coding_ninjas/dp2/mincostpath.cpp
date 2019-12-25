#include <iostream>
#include <vector>
#include <climits>
#include <bits/stdc++.h>

using namespace std;
/// ****************************** Brute Force ************************
int minCost(int **input,int i,int j ,int m, int n) {
    /* Don't write main().
     * Don't read input, it is passed as function argument.
     * Return output and don't print it.
     * Taking input and printing output is handled automatically.
     */
    if(i+1==m && j+1==n)
        return input[m-1][n-1];
    
    vector<int> min;
    int x,y,z;
    if(i+1<m && j<  n)
    {
       x = minCost(input,i+1,j,m,n);
       min.push_back(x);
    }
    if(i<m && j+1 < n)
    {
        y = minCost(input,i,j+1,m,n);
        min.push_back(y);
    }
    if(i+1<m && j+1<n)
    {
        z = minCost(input,i+1,j+1,m,n);
        min.push_back(z);
    }
    sort(min.begin(),min.end());
    
    return min[0] + input[i][j];
}
//****************************************** Memorisation ***********************
int minCostmemo(int **input,int i,int j,int m, int n,int output[][]) {
    /* Don't write main().
     * Don't read input, it is passed as function argument.
     * Return output and don't print it.
     * Taking input and printing output is handled automatically.
     */
    if(i+1==m && j+1==n)
        return input[m-1][n-1];
    if(output[i][j] != -1)
        return output[i][j];
    vector<int> min;
    int x,y,z;
    if(i+1<m && j<  n)
    {
       x = minCostmemo(input,i+1,j,m,n,output);
       min.push_back(x);
    }
    if(i<m && j+1 < n)
    {
        y = minCostmemo(input,i,j+1,m,n,output);
        min.push_back(y);
    }
    if(i+1<m && j+1<n)
    {
        z = minCostmemo(input,i+1,j+1,m,n,output);
        min.push_back(z);
    }
    sort(min.begin(),min.end());
     output[i][j] = min[0];   
    
    return output[i][j];
}
//****************************************
//******************************DP*******************
int minCostPathDP(int **input, int m, int n) {
    
    
    int output[m][n];
    
    output[m-1][n-1] = input[m-1][n-1];
    //for row laft to right 
    for(int i= n-2;i>=0;i--)
    {
        output[m-1][i] = output[m-1][i+1] + input[m-1][i]; 
    }
       //for column down to up 
    cout << endl;
    for(int i= m-2;i>=0;i--)
    {
        output[i][n-1] = output[i+1][n-1] + input[i][n-1];
    }
    
    for(int i=m-2;i>=0;i--)
    {
        for(int j=n-2;j>=0;j--)
        {
            output[i][j] = min(output[i+1][j],min(output[i][j+1],output[i+1][j+1])) + input[i][j];
        }
    }
   return output[0][0]; 
}

//**************************
int minCostPath(int **input, int m, int n) {
    int output[m][n];
    for(int i=0;i<m;i++)
        for(int j=0;j<n;j++)
          output[i][j]=-1;
    //int min = minCost(input,0,0,m,n);
     int min = minCostmemo(input,0,0,m,n,output);
     int min = minCostPathDP(input,m,n);
    return min;
}

