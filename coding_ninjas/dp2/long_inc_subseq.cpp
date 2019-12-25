#include <iostream>
#include<bits/stdc++.h> 
using namespace std;

 int lis(int arr[], int n) {
		
				
	/*Write your code here. 
	 *Don't write main().
	 *Don't take input, it is passed as function argument.
	 *Don't print output.
	 *Taking input and printing output is handled automatically.
	*/ 
  
    int list[n]; 
   
    list[0] = 1;    
  
    /* Compute optimized LIS values in bottom up manner */
    for (int i = 1; i < n; i++ )  
    { 
        list[i] = 1; 
        for (int j = 0; j < i; j++ )   
            if ( arr[i] > arr[j] && list[i] < list[j] + 1)  
                list[i] = list[j] + 1;  
    } 
  
    // Return maximum value in lis[] 
    return *max_element(list, list+n);
 }
