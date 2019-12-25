#include <iostream>
using namespace std;
int getMaxMoney(int a[], int n){
    if (n == 1)
        return a[0];
    if (n == 2)
        return max(a[0], a[1]);
    int * dp = (int * ) malloc(sizeof(int) * n);
    for (int i = 0; i < n; i++)
        dp[i] = 0;
    dp[0] = a[0];
    dp[1] = max(a[0], a[1]);
    for (int i = 2; i < n; i++)
        dp[i] = max(dp[i - 2] + a[i], dp[i - 1]);
    int t = dp[n - 1];
 
    return t;
}

