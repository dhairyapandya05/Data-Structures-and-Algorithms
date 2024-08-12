class Solution {
public:
    int minDistance(string word1, string word2) {
        int n = word1.length();
        int m = word2.length();
        if(n==0){
            return m;
        }
        if(m==0){
            return n;
        }
        // vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));
        // for (int j = 0; j <= m; j++) {
        //     dp[n][j] = m - j;
        // }
        // for (int i = 0; i <= n; i++) {
        //     dp[i][m] = n - i;
        // }
        vector<int> curr(m + 1, 0);
        vector<int> next(m + 1, 0);
        for (int j = 0; j <= m; j++) {
            next[j] = m - j;
        }
        for (int i = n - 1; i >= 0; i--) {
            for (int j = m - 1; j >= 0; j--) {
                curr[m] = n - i;
                int ans;
                if (word1[i] == word2[j]) {
                    ans = next[j + 1];
                } else {
                    int insertion = 1 + curr[j + 1];
                    int deletion = 1 + next[j];
                    int replace = 1 + next[j + 1];
                    ans = min({insertion, deletion, replace});
                }
                curr[j] = ans;
            }
            next = curr;
        }
        return next[0];
    }
};