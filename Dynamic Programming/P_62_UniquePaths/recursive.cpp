class Solution {
public:
    int solve(int i, int j, int& m, int& n) {
        if (i < 0 or i >= m or j < 0 or j >= n) {
            return 0;
        }
        if (i == m - 1 or j == n - 1) {
            return 1;
        }
        int down = solve(i + 1, j, m, n);
        int up = solve(i, j + 1, m, n);
        return up + down;
    }
    int uniquePaths(int m, int n) { return solve(0, 0, m, n); }
};