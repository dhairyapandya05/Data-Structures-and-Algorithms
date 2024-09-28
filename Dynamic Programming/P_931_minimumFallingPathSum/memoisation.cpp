class Solution {
public:
    int solve(int row,int col,vector<vector<int>>& matrix,vector<vector<int>>& dp){
        if(row==matrix.size()){
            return 0;
        }
        if(dp[row][col]!=-1){
            return dp[row][col];
        }
        int ans1=INT_MAX,ans2=INT_MAX,ans3=INT_MAX;
        if(col-1>=0){
            ans1=solve(row+1,col-1,matrix,dp);
        }
        
        ans2=solve(row+1,col,matrix,dp);
        if(col+1<matrix.size()){
            ans3=solve(row+1,col+1,matrix,dp);
        }
        return dp[row][col]=matrix[row][col]+min({ans1,ans2,ans3});
    }
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int n=matrix.size();
        int m=matrix[0].size();
        int row=0;
        int ans=INT_MAX;
        vector<vector<int>>dp(n,vector<int>(m,-1));
        for(int col=0;col<n;col++){
            ans=min(ans,solve(row,col,matrix,dp));
        }
        return ans;
    }
};