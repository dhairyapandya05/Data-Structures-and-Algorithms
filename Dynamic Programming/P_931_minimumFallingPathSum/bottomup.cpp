class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();
        int row = 0;
        vector<vector<int>> dp(n + 1, vector<int>(m, 0));
        for (int row = n - 1; row >= 0; row--) {
            for (int col = 0; col < m; col++) {
                int ans1 = INT_MAX, ans2 = INT_MAX, ans3 = INT_MAX;
                if (col - 1 >= 0) {
                    ans1 = dp[row + 1][col - 1];
                }

                ans2 = dp[row + 1][col];
                if (col + 1 < matrix.size()) {
                    ans3 = dp[row + 1][col + 1];
                }
                dp[row][col] = matrix[row][col] + min({ans1, ans2, ans3});
            }
        }
        return *min_element(dp[0].begin(),dp[0].end());
    }
};