class Solution {
public:
    int solve(int i, int j, int& m, int& n, vector<vector<int>>& dp) {
        if (i < 0 or i >= m or j < 0 or j >= n) {
            return 0;
        }
        if (i == m - 1 or j == n - 1) {
            return 1;
        }
        if (dp[i][j] != -1) {
            return dp[i][j];
        }
        int down = solve(i + 1, j, m, n, dp);
        int up = solve(i, j + 1, m, n, dp);
        return dp[i][j] = up + down;
    }
    int uniquePaths(int m, int n) {
        vector<vector<int>> dp(m + 1, vector<int>(n + 1, -1));
        return solve(0, 0, m, n, dp);
    }
};