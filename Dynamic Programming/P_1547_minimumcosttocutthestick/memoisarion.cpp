class Solution {
public:
    int solve(int i,int j, vector<int>& cuts,vector<vector<int>>& dp){
        if(i>j){
            return 0;
        }
        if(dp[i][j]!=-1){
            return dp[i][j];
        }
        int mini=1e9;
        for(int k=i;k<=j;k++){
            int steps=solve(i,k-1,cuts,dp)+solve(k+1,j,cuts,dp)+(cuts[j+1]-cuts[i-1]);
            mini=min(mini,steps);
        }
        return dp[i][j]=mini;
    }
    int minCost(int n, vector<int>& cuts) {
        cuts.push_back(0);
        cuts.push_back(n);
        int c=cuts.size();
        vector<vector<int>>dp(c,vector<int>(c,-1));
        sort(cuts.begin(),cuts.end());
        return solve(1,c-2,cuts,dp);
    }
};