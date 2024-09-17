class Solution {
public:
    int solve(int i,int level,int& n,vector<vector<int>>& triangle,vector<vector<int>>& dp){
        if(level>=n){
            return 0;
        }
        if(dp[i][level]!=-1){
            return dp[i][level];
        }
        int ithIndex=solve(i,level+1,n,triangle,dp)+triangle[level][i];
        int inextthIndex=INT_MAX;
        if(i+1<triangle[level].size())
        inextthIndex=solve(i+1,level+1,n,triangle,dp)+triangle[level][i+1];
        return dp[i][level]=min(ithIndex,inextthIndex);
    }
    int minimumTotal(vector<vector<int>>& triangle) {
        int idx=0,n=triangle.size();
        vector<vector<int>> dp(n,vector<int>(n,-1));
        int ans=solve(idx,0,n,triangle,dp);
        return ans;
    }
};