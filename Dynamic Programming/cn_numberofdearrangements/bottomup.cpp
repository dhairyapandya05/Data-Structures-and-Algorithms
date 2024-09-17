#include <bits/stdc++.h>
#define MOD int (1e9+7);
long long int countDerangements(int n) {
    // Write your code here.
    vector<long long int> dp (n+1,0);
    dp[0]=0;
    dp[1]=0;
    dp[2]=1;
    for (int i = 3; i <= n; i++) {
        dp[i]=(i-1)*(dp[i-1]+dp[i-2])%MOD;
    }
    return dp[n]%MOD;
}