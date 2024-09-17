#include <bits/stdc++.h>
#define MOD int (1e9+7);
long long int countDerangements(int n) {
    long long int prev2=0;
    long long int prev1=1;
    if (n <= 1) {
        return prev2;
    }
    if (n == 2) {
        return prev1;
    }
    long long int curr;
    for (int i = 3; i <= n; i++) {
        curr=((i-1)*(prev1+prev2))%MOD;
        prev2=prev1;
        prev1=curr;
    }
    return curr%MOD;
}