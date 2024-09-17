#include<bits/stdc++.h>
long solve(int i,long *values, bool buyexecution, int n,vector<vector<long>>& dp) {
    if (i == n) {
        return 0;
    }
    if (dp[buyexecution][i] != -1) {
        return dp[buyexecution][i];
    }
    long profit=0;
    if(buyexecution){
        profit=max(-values[i] +solve(i+1,values,false,n,dp),solve(i+1,values,true,n,dp));
    } else {
        profit=max(values[i]+solve(i+1,values,true,n,dp),solve(i+1,values,false,n,dp));
    }
    dp[buyexecution][i]=profit;
    return profit;
}
long getMaximumProfit(long *values, int n)
{
    //Write your code here
    bool buyexecution=true;
    vector<vector<long>> dp(2,vector<long>(n+1,-1));
    long ans=solve(0,values,buyexecution,n,dp);
    return ans;
}