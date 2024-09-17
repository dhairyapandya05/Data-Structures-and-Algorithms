#include<bits/stdc++.h>
long solve(int i,vector<int> &values, bool buyexecution, int n,vector<vector<int>>& dp) {
    if (i >= n) {
        return 0;
    }
    if (dp[buyexecution][i] != -1) {
        return dp[buyexecution][i];
    }
    long profit=0;
    if(buyexecution){
        profit=max(-values[i] +solve(i+1,values,false,n,dp),solve(i+1,values,true,n,dp));
    } else {
        profit=max(values[i]+solve(i+2,values,true,n,dp),solve(i+1,values,false,n,dp));
    }
    dp[buyexecution][i]=profit;
    return profit;
}
int stockProfit(vector<int> &prices){
    // Write your code here.
    int n=prices.size();
    bool buyexecution=true;
    vector<vector<int>> dp(2,vector<int>(n+1,-1));
    int ans=solve(0,prices,buyexecution,n,dp);
    return ans;
}