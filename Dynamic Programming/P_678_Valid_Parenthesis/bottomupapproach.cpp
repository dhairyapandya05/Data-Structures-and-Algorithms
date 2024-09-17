class Solution {
public:
    bool checkValidString(string s) {
        int n = s.length();
        vector<vector<int>> dp(n + 1, vector<int>(n + 1, 0));
        dp[n][0] = 1;
        for (int idx = n - 1; idx >= 0; idx--) {
            for (int count = 0; count <= n; count++) {
                if (s[idx] == '(') {
                    if (count + 1 <= n)
                    dp[idx][count] = dp[idx + 1][count + 1];
                }
                else if (s[idx] == ')') {
                    if(count-1>=0)
                    dp[idx][count] = dp[idx + 1][count - 1];
                } else {
                    if (count + 1 <= n)
                    dp[idx][count] = dp[idx][count] or dp[idx + 1][count + 1];
                    if(count-1>=0)
                    dp[idx][count] = dp[idx][count] or dp[idx + 1][count - 1];
                    dp[idx][count]=dp[idx][count] or dp[idx + 1][count];
                }
            }
        }
        return dp[0][0];
        // return solve(0, 0, s,dp);
    }
};