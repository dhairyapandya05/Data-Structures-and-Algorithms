// can also be solve recursively through dfs Important:

class Solution {
public:
    void markgridasguarded(int i, int j, vector<vector<int>> &grid) {
        for (int row = i - 1; row >= 0; row--) {
            if (grid[row][j] == 2 or grid[row][j] == 3)
                break;
            grid[row][j] = -2;
        }
        for (int row = i + 1; row < grid.size(); row++) {
            if (grid[row][j] == 2 or grid[row][j] == 3)
                break;
            grid[row][j] = -2;
        }
        for (int col = j + 1; col < grid[0].size(); col++) {
            if (grid[i][col] == 2 or grid[i][col] == 3)
                break;
            grid[i][col] = -2;
        }

        for (int col = j - 1; col >= 0.; col--) {
            if (grid[i][col] == 2 or grid[i][col] == 3)
                break;
            grid[i][col] = -2;
        }
    }
    int countUnguarded(int m, int n, vector<vector<int>> &guards,
                       vector<vector<int>> &walls) {
        vector<vector<int>> grid(m, vector<int>(n, 0));
        for (auto it : guards) {
            grid[it[0]][it[1]] = 2; // marking them as guard
        }
        for (auto it : walls) {
            grid[it[0]][it[1]] = 3; // marking them as wall
        }
        for (auto it : guards) {
            markgridasguarded(it[0], it[1], grid);
        }
        int count = 0;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                cout << grid[i][j] << " ";
                if (grid[i][j] == 0)
                    count++;
            }
            cout << endl;
        }
        return count;
    }
};

// - 2 can is guarded by the guard 2 positon of guard 3 position of wall 0 unvisited or unguarded

// Approach-2 (DFS)
// T.C : O(m*n + G*(m+n)), where G =  size of guards
// S.C : O(m*n), considering the size of grid we took
class Solution {
public:
    void dfs(vector<vector<int>> &grid, int row, int col, int rows, int cols, int direction) {
        // Boundary check and skipping guarded or walled cells
        if (row < 0 || col < 0 || row >= rows || col >= cols || grid[row][col] == 1 || grid[row][col] == 2) {
            return;
        }

        // Mark the current cell as visited by a guard's line of sight
        grid[row][col] = 3;

        // Continue the DFS in the specified direction
        if (direction == 1) { // UP
            dfs(grid, row - 1, col, rows, cols, direction);
        } else if (direction == 2) { // DOWN
            dfs(grid, row + 1, col, rows, cols, direction);
        } else if (direction == 3) { // LEFT
            dfs(grid, row, col - 1, rows, cols, direction);
        } else { // RIGHT
            dfs(grid, row, col + 1, rows, cols, direction);
        }
    }

    int countUnguarded(int rows, int cols, vector<vector<int>> &guards, vector<vector<int>> &walls) {
        // Initialize the grid
        vector<vector<int>> grid(rows, vector<int>(cols, 0));

        // Mark guard positions
        for (const auto &guard : guards) {
            int i = guard[0];
            int j = guard[1];
            grid[i][j] = 1; // Guard cell
        }

        // Mark wall positions
        for (const auto &wall : walls) {
            int i = wall[0];
            int j = wall[1];
            grid[i][j] = 2; // Wall cell
        }

        // Perform DFS for each guard in all four directions (UP, DOWN, LEFT, RIGHT)
        for (const auto &guard : guards) {
            int guardRow = guard[0];
            int guardCol = guard[1];

            dfs(grid, guardRow - 1, guardCol, rows, cols, 1); // UP
            dfs(grid, guardRow + 1, guardCol, rows, cols, 2); // DOWN
            dfs(grid, guardRow, guardCol - 1, rows, cols, 3); // LEFT
            dfs(grid, guardRow, guardCol + 1, rows, cols, 4); // RIGHT
        }

        // Count unguarded cells
        int unguardedCount = 0;
        for (int row = 0; row < rows; ++row) {
            for (int col = 0; col < cols; ++col) {
                if (grid[row][col] == 0) {
                    ++unguardedCount;
                }
            }
        }

        return unguardedCount;
    }
};