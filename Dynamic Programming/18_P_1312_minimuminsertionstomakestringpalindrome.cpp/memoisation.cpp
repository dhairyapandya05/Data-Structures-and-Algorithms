class Solution {
public:
    int solve(int i, int j, string& s, vector<vector<int>>& dp) {
        if (i >= j) {
            return 0;
        }
        if (dp[i][j] != -1) {
            return dp[i][j];
        }
        if (s[i] == s[j]) {
            return dp[i][j] = solve(i + 1, j - 1, s, dp);
        } else {
            return dp[i][j] =
                       min(solve(i + 1, j, s, dp), solve(i, j - 1, s, dp)) + 1;
        }
    }
    int minInsertions(string s) {
        int n = s.length();
        vector<vector<int>> dp(n, vector<int>(n, -1));
        int ans = solve(0, n - 1, s, dp);
        return ans;
    }
};
// Method 2 most important

// minimum number of insertions is n-longest palindromic subsequence