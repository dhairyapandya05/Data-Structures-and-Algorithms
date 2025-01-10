#include <bits/stdc++.h>
int subarraysWithSumK(vector<int> a, int b) {
    // Write your code here
    unordered_map<int, int> mp;
    int cnt = 0;
    int n = a.size();
    mp[0] = 1; // initial
    int xr = 0;
    for (int i = 0; i < n; i++) {
        xr = xr ^ a[i];
        int fnd = b ^ xr;
        cnt += mp[fnd];
        mp[xr]++;
    }
    return cnt;
}