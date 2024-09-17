class Solution {
public:
    bool solve(int idx, int count, string s,vector<vector<int>>& dp) {
        if (count < 0) {
            return false;
        }
        if (idx >= s.length()) {
            return (count == 0);
        }
        if(dp[idx][count]!=-1){
            return dp[idx][count];
        }
        if (s[idx] == '(') {
            return dp[idx][count]=solve(idx + 1, count + 1, s,dp);
        } else if (s[idx] == ')') {
            return dp[idx][count]=solve(idx + 1, count - 1, s,dp);
        }
        return dp[idx][count]=solve(idx + 1, count + 1, s,dp) or solve(idx + 1, count - 1, s,dp) or
               solve(idx + 1, count, s,dp);
    }
    bool checkValidString(string s) { 
        int n=s.length();
        vector<vector<int>>dp (n,vector<int>(n,-1));
        return solve(0, 0, s,dp); }
};