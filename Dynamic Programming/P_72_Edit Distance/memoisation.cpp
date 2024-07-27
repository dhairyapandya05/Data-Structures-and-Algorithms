class Solution {
public:
    int solve(int i, int j, string& word1, string& word2,
              vector<vector<int>>& dp) {
        if (i >= word1.length()) {
            return word2.length() - j;
        }
        if (j >= word2.length()) {
            return word1.length() - i;
        }
        if (dp[i][j] != -1) {
            return dp[i][j];
        }
        int ans;
        if (word1[i] == word2[j]) {
            ans = solve(i + 1, j + 1, word1, word2, dp);
        } else {
            int insertion = 1 + solve(i, j + 1, word1, word2, dp);
            int deletion = 1 + solve(i + 1, j, word1, word2, dp);
            int replace = 1 + solve(i + 1, j + 1, word1, word2, dp);
            ans = min({insertion, deletion, replace});
        }
        return dp[i][j] = ans;
    }
    int minDistance(string word1, string word2) {
        vector<vector<int>> dp(word1.length() + 1,
                               vector<int>(word2.length() + 1, -1));
        int ans = solve(0, 0, word1, word2, dp);
        return ans;
    }
};