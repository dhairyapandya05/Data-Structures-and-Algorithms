class Solution {
public:
    bool isSafe(int i, int j, vector<vector<int>> &grid) {
        return i >= 0 and i < grid.size() and j >= 0 and j < grid[0].size();
    }
    int solve(int i, int j, vector<vector<int>> &grid) {
        if (!isSafe(i, j, grid) or grid[i][j] == 2 or grid[i][j] == 0) {
            return 0;
        }
        grid[i][j] = 2;
        int bottom = solve(i + 1, j, grid);
        int top = solve(i - 1, j, grid);
        int right = solve(i, j + 1, grid);
        int left = solve(i, j - 1, grid);
        return bottom + right + left + top + 1;
    }
    int maxAreaOfIsland(vector<vector<int>> &grid) {
        int maxarea = INT_MIN;
        for (int i = 0; i < grid.size(); i++) {
            for (int j = 0; j < grid[0].size(); j++) {
                if (grid[i][j] == 1) {
                    int ans = solve(i, j, grid);
                    maxarea = max(ans, maxarea);
                }
            }
        }
        return (maxarea == INT_MIN) ? 0 : maxarea;
    }
};