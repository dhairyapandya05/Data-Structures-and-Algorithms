class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        int n = triangle.size();
        vector<vector<int>> dp(n, vector<int>(n, 0));
        for (int i = 0; i < n; i++) {
            dp[n-1][i] = triangle[n - 1][i]; // handling the base case
        }
        for (int level = n - 2; level >= 0; level--) {
            for (int i = 0; i <=level; i++) {
                dp[level][i] = triangle[level][i] + min(dp[level + 1][i], dp[level + 1][i + 1]);
            }
        }
        return dp[0][0];
    }
};