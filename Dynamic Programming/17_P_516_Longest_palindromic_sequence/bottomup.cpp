class Solution {
public:
    int longestPalindromeSubseq(string s) {
        int n = s.length();
        vector<vector<int>> dp(n, vector<int>(n, 0));
        // int ans = solve(s, 0, n - 1, dp);
        // return ans;
        int maxlen = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (i == j) {
                    dp[i][j] = 1;
                    maxlen = 1;
                }
            }
        }
        for (int L = 2; L <= n; L++) {
            for (int i = 0; L + i - 1 < n; i++) {
                int j = L + i - 1;
                if (s[i] == s[j]) {
                    dp[i][j] = 2 + dp[i + 1][j - 1];
                } else {
                    dp[i][j] = max(dp[i][j - 1], dp[i + 1][j]);
                }
            }
        }
        return dp[0][n-1];
    }
};
// other method of solving this question is by passing string s and string reverse of s in lcs function