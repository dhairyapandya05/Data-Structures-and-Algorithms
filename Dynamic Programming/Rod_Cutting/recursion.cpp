#include <bits/stdc++.h>
int solve(int n, int x, int y, int z) {
  	if (n==0) {
	  return 0;
  	}
    if (n < 0) {
        return INT_MIN;
	}
    int segmentfromX=solve(n-x,x,y,z)+1;
	int segmentfromY=solve(n-y,x,y,z)+1;
	int segmentfromZ=solve(n-z,x,y,z)+1;
    return max(max(segmentfromX,segmentfromY),segmentfromZ);
}
int cutSegments(int n, int x, int y, int z) {
	// Write your code here.
	int ans= solve(n,x,y,z);
    if (ans < 0) {
		return 0;
	}
	return ans;
}
// link:https://www.naukri.com/code360/problems/cut-into-segments_1214651?topList=love-babbar-dsa-sheet-problems&leftPanelTab=0&utm_source=youtube&utm_medium=affiliate&utm_campaign=Lovebabbar&leftPanelTabValue=PROBLEM