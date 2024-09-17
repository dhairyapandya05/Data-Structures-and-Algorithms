#include <bits/stdc++.h>
#define MOD 1000000007;
long long int solve(int n){
  if (n == 0 or n==1) {
      return 0;
  }
  if (n == 2) {
      return 1;
  }
  return (n-1)*(solve(n-1)+solve(n-2));
}
long long int countDerangements(int n) {
    // Write your code here.
    return solve(n)%MOD;
}