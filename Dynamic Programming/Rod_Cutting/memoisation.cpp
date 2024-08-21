#include <bits/stdc++.h>
int solve(int n, int x, int y, int z,vector<int>& dp) {
  	if (n==0) {
	  return 0;
  	}
    if (n>=0 and dp[n] != -1) {
		return dp[n];
    }
    if (n < 0) {
        return INT_MIN;
	}
    int segmentfromX=solve(n-x,x,y,z,dp)+1;
	int segmentfromY=solve(n-y,x,y,z,dp)+1;
	int segmentfromZ=solve(n-z,x,y,z,dp)+1;
    return dp[n]=max(max(segmentfromX,segmentfromY),segmentfromZ);
}
int cutSegments(int n, int x, int y, int z) {
	// Write your code here.
	vector<int>dp(n+1,-1);
	int ans= solve(n,x,y,z,dp);
    if (ans < 0) {
		return 0;
	}
	return ans;
}