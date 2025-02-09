class Solution {
public:
    int maxvalue = 0;
    bool isSafe(int i, int j, int &n, int &m) {
        return i >= 0 and i < n and j >= 0 and j < m;
    }
    int solve(int i, int j, int &n, int &m, vector<vector<int>> &grid, int value, vector<vector<int>> &dp) {
        // Check if we have reached the last column
        if (j == m) {
            // maxvalue = max(maxvalue, value);
            return 0;
        }
        if (dp[i][j] != -1) {
            return dp[i][j];
        }
        value += grid[i][j];
        int ans1 = 0, ans2 = 0, ans3 = 0;
        if (isSafe(i + 1, j + 1, n, m) and grid[i + 1][j + 1] > grid[i][j]) {
            ans1 = solve(i + 1, j + 1, n, m, grid, value, dp) + 1;
        }
        if (isSafe(i, j + 1, n, m) and grid[i][j + 1] > grid[i][j]) {
            ans2 = solve(i, j + 1, n, m, grid, value, dp) + 1;
        }
        if (isSafe(i - 1, j + 1, n, m) and grid[i - 1][j + 1] > grid[i][j]) {
            ans3 = solve(i - 1, j + 1, n, m, grid, value, dp) + 1;
        }
        return dp[i][j] = max({ans1, ans2, ans3});
    }
    int maxMoves(vector<vector<int>> &grid) {
        int n = grid.size();
        int m = grid[0].size();
        int value = 0;
        vector<vector<int>> dp(n, vector<int>(m, -1));
        for (int i = 0; i < n; i++) {
            int ans = solve(i, 0, n, m, grid, value, dp);
            maxvalue = max(maxvalue, ans);
        }
        return maxvalue;
    }
};