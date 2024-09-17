#include<bits/stdc++.h>

int stockProfit(vector<int> &values){
    int n=values.size();
    vector<vector<long>> dp(2,vector<long>(n+2,0));
    dp[0][n]=0;
    dp[1][n]=0;
    dp[0][n+1]=0;
    dp[1][n+1]=0;
    for (int i = n-1; i >=0; i--) {
        for(int buy=0;buy<=1;buy++){
            long profit=0;
            if(buy){
                profit=max(-values[i] +dp[0][i+1],dp[1][i+1]);
            } 
            else {
                profit=max(values[i]+dp[1][i+2],dp[0][i+1]);
            }
        dp[buy][i]=profit;
        }
    }
    return dp[1][0];
}