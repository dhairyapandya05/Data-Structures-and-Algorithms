class Solution {
public:
    int minDistance(string word1, string word2) {
        int n = word1.length();
        int m = word2.length();
        vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));
        for (int j = 0; j <= m; j++) {
            dp[n][j] = m - j;
        }
        for (int i = 0; i <= n; i++) {
            dp[i][m] = n - i;
        }

        for (int i = n-1; i >= 0; i--) {
            for (int j = m-1; j >= 0; j--) {
                int ans;
                if (word1[i] == word2[j]) {
                    ans = dp[i + 1][j + 1];
                } else {
                    int insertion = 1 + dp[i][j + 1];
                    int deletion = 1 + dp[i + 1][j];
                    int replace = 1 + dp[i + 1][j + 1];
                    ans = min({insertion, deletion, replace});
                }
                dp[i][j] = ans;
            }
        }
        return dp[0][0];
    }
};