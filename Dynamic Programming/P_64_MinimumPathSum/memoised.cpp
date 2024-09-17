class Solution {
public:
    int solve(int i, int j, int& n, int& m, vector<vector<int>>& grid,
              vector<vector<int>>& dp) {
        if (i >= n || j >= m)
            return INT_MAX;
        if (i == n - 1 and j == m - 1) {

            return grid[i][j];
        }
        if (dp[i][j] != -1) {
            return dp[i][j];
        }
        int down = solve(i + 1, j, n, m, grid, dp);
        int right = solve(i, j + 1, n, m, grid, dp);
        return dp[i][j] = min(down, right) + grid[i][j];
    }
    int minPathSum(vector<vector<int>>& grid) {
        int mini = INT_MAX;
        int temppath = 0;
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<int>> dp(n, vector<int>(m, -1));
        int ans = solve(0, 0, n, m, grid, dp);
        return ans;
    }
};