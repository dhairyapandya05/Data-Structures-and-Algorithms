// #include<bits/stdc++.h>
int solve(int idx, bool canBuy, int limit, vector<int> &prices, int &n,vector<vector<vector<int>>>& dp) {
    if(idx==n){
        return 0;
    }
    if(limit==0){
        return 0;
    }
    if(dp[idx][canBuy][limit] != -1) {
        return dp[idx][canBuy][limit];
    }
    if(canBuy){
        return dp[idx][canBuy][limit]=max(-prices[idx]+solve(idx+1,0,limit,prices,n,dp),
            solve(idx+1,1,limit,prices,n,dp));
    }
    return dp[idx][canBuy][limit]=max(prices[idx]+solve(idx+1,1,limit-1,prices,n,dp),
            solve(idx+1,0,limit,prices,n,dp));
}
int maxProfit(vector<int>& prices)
{
    // Write your code here.
    int idx=0;
    bool canBuy=true;
    int n=prices.size();
    int limit=2;
    vector<vector<vector<int>>>dp(n+1,vector<vector<int>>(2,vector<int>(limit+1,-1)));
    return solve(idx,canBuy,limit,prices,n,dp);
}