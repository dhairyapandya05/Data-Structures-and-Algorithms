class Solution {
public:
    bool solve(int i,int j,string& s1, string& s2,vector<vector<int>>& dp){
        //basecase
        if(i<0 and j<0){
            return true;
        }
        if(j<0 and i>=0){
            return false;
        }
        if(i<0 and j>=0){
            for(int k=0;k<=j;k++){
                if(s2[k]!='*'){
                    return false;
                }
            }
            return true;
        }
        if(dp[i][j]!=-1){
            return (dp[i][j]>0)?true:false;
        }
        //if string match
        if(s1[i]==s2[j] or s2[j]=='?'){
            return solve(i-1,j-1,s1,s2,dp);
        }
        else if(s2[j]=='*'){
            return dp[i][j]=(solve(i,j-1,s1,s2,dp) or solve(i-1,j,s1,s2,dp));
        }
        else{
            dp[i][j]=false;
            return false;
        }
    }
    bool isMatch(string s, string p) {
        int n=s.length();
        int m=p.length();
        vector<vector<int>> dp(n+1,vector<int>(m+1,-1));
        return solve(s.length()-1,p.length()-1,s,p,dp);
    }
};