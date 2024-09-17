class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<int>> dp(n, vector<int>(m, 0));
        // Start by initializing the bottom-right corner
        dp[n - 1][m - 1] = grid[n - 1][m - 1];
        // Initialize the last row (can only move right)
        for (int i = n - 2; i >= 0; i--) {
            dp[i][m - 1] = grid[i][m - 1] + dp[i + 1][m - 1];
        }

        // Initialize the last column (can only move down)
        for (int j = m - 2; j >= 0; j--) {
            dp[n - 1][j] = grid[n - 1][j] + dp[n - 1][j + 1];
        }
        for (int i = n - 2; i >= 0; i--) {
            for (int j = m - 2; j >= 0; j--) {
                int down = dp[i + 1][j];
                int right = dp[i][j + 1];
                dp[i][j] = min(down, right) + grid[i][j];
            }
        }
        return dp[0][0];
    }
};