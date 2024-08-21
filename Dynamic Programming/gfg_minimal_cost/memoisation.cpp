class Solution {
  public:
    int solve(vector<int>& arr,int n, int& k,vector<int>& dp){
        if(n==0){
            return 0;
        }
        if(dp[n]!=-1){
            return dp[n];
        }
        int mini=INT_MAX;
        for(int i=1;i<=k;i++){
            int ans=INT_MAX;
            if(n-i>=0)
            ans=solve(arr,n-i,k,dp)+abs(arr[n]-arr[n-i]);
            mini=min(mini,ans);
        }
        return dp[n]=mini;
    }
    int minimizeCost(vector<int>& arr, int& k) {
        // Code here
        int n=arr.size();
        vector<int>dp(n,-1);
        return solve(arr,n-1,k,dp);
    }
};