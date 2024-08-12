class Solution
{
    public:
    int solve(string& str1, string& str2, int i,int j,int& m, int& n,vector<vector<int>>& dp){
        if(i>=m){
            return n-j;
        }
        if(j>=n){
            return m-i;
        }
        if(dp[i][j]!=-1){
            return dp[i][j];
        }
        int ans=INT_MAX;
        if(str1[i]==str2[j]){
            ans=1+solve(str1,str2,i+1,j+1,m,n,dp);
        }
        else{
            ans=min(solve(str1,str2,i+1,j,m,n,dp),solve(str1,str2,i,j+1,m,n,dp))+1;
        }
        return dp[i][j]=ans;
    }
    //Function to find length of shortest common supersequence of two strings.
    int shortestCommonSupersequence(string X, string Y, int m, int n)
    {
        //code here
        vector<vector<int>> dp(m,vector<int>(n,-1));
        int ans=solve(X,Y,0,0,m,n,dp);
        return ans;
    }
};