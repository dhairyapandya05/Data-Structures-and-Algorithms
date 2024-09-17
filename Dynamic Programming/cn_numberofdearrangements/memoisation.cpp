#include <bits/stdc++.h>
#define MOD int (1e9+7);
long long int solve(int n,vector<long long int>& dp){
  if (n == 0 or n==1) {
      return 0;
  }
  if (n == 2) {
      return 1;
  }
  if (dp[n] != -1) {
      return dp[n];
  }
  return dp[n]= (n-1)*(solve(n-1,dp)+solve(n-2,dp))%MOD;
}
long long int countDerangements(int n) {
    // Write your code here.
    vector<long long int> dp (n+1,-1);
    return solve(n,dp)%MOD;
}