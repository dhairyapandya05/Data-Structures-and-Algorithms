class Solution {
public:
    int solve(int i, int j, int& m, int& n,vector<vector<int>>& obstacleGrid) {
        if (i < 0 or i >= m or j < 0 or j >= n) {
            return 0;
        }
        if(obstacleGrid[i][j]==1){
            return 0;
        }
        if ((i == m - 1 and j == n - 1) and obstacleGrid[i][j]!=1) {
            return 1;
        }
        int down = solve(i + 1, j, m, n,obstacleGrid);
        int up = solve(i, j + 1, m, n,obstacleGrid);
        return (up + down)%2000000000;
    }
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int m=obstacleGrid.size();
        int n=obstacleGrid[0].size();
        return solve(0,0,m,n,obstacleGrid);
    }
};