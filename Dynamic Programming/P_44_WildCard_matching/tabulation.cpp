class Solution {
public:
    bool isMatch(string s, string p) {
        int n = s.length();
        int m = p.length();
        vector<vector<bool>> dp(n + 1, vector<bool>(m + 1, false));
        dp[0][0] = true;
        for (int i = 1; i < n + 1; i++) {
            dp[i][0] = false;
        }
        for (int j = 1; j < m + 1; j++) {
            bool flag = true;
            for (int k = 1; k <= j; k++) {
                if (p[k - 1] != '*') {
                    flag = false;
                    break;
                }
            }
            dp[0][j] = flag;
        }

        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= m; j++) {
                // if string match
                if (i > 0 and j > 0 and
                    (s[i - 1] == p[j - 1] or p[j - 1] == '?')) {
                    dp[i][j]= dp[i - 1][j - 1];
                } else if (j > 0 and p[j - 1] == '*') {
                    dp[i][j] = (dp[i][j-1] or dp[i-1][j]);
                } else {
                    dp[i][j] = false;
                }
            }
        }
        return dp[n][m];
    }
};