class Solution {
public:
    int maxelement(vector<vector<int>>& grid, int row, int col) {
        int maxele = INT_MIN;
        for (int i = row; i < row + 3; i++) {
            for (int j = col; j < col + 3; j++) {
                maxele = max(maxele, grid[i][j]);
            }
        }
        return maxele;
    }
    vector<vector<int>> largestLocal(vector<vector<int>>& grid) {
        int n = grid.size();
        vector<vector<int>> mat(n - 2, vector<int>(n - 2));
        for (int row = 0; row < n - 2; row++) {
            for (int col = 0; col < n - 2; col++) {
                mat[row][col] = maxelement(grid, row, col);
            }
        }
        return mat;
    }
};