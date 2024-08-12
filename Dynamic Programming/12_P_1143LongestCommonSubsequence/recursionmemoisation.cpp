class Solution {
public:
    int solve(int i,int j,string& txt1,string& txt2,vector<vector<int>>& dp){
        if(i>=txt1.length() or j>=txt2.length()){
            return 0;
        }
        if(dp[i][j]!=-1){
            return dp[i][j];
        }
        int ans=0;
        if(txt1[i]==txt2[j]){
            ans=1+solve(i+1,j+1,txt1,txt2,dp);
        }
        else{
            ans=max(solve(i+1,j,txt1,txt2,dp),solve(i,j+1,txt1,txt2,dp));
        }
        return dp[i][j]=ans;
    }
    int longestCommonSubsequence(string text1, string text2) {
        vector<vector<int>> dp(text1.length(),vector<int> (text2.length(),-1));
        int ans=solve(0,0,text1,text2,dp);
        return ans;
    }
};