class Solution {
public:
    int solve(int i, int j, int& m, int& n,vector<vector<int>>& obstacleGrid,vector<vector<int>>& dp) {
        if (i < 0 or i >= m or j < 0 or j >= n) {
            return 0;
        }
        if(dp[i][j]!=-1){
            return dp[i][j];
        }
        if(obstacleGrid[i][j]==1){
            return 0;
        }
        if ((i == m - 1 and j == n - 1) and obstacleGrid[i][j]!=1) {
            return 1;
        }
        int down = solve(i + 1, j, m, n,obstacleGrid,dp);
        int up = solve(i, j + 1, m, n,obstacleGrid,dp);
        return dp[i][j]=(up + down)%2000000000;
    }
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int m=obstacleGrid.size();
        int n=obstacleGrid[0].size();
        vector<vector<int>> dp(m + 1, vector<int>(n + 1, -1));
        return solve(0,0,m,n,obstacleGrid,dp);
    }
};