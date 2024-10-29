class Solution {
public:
    // int solve(vector<int>& nums, int i, int j, vector<vector<int>>& dp) {
    //     if (i > j) {
    //         return 0;
    //     }
    //     if (dp[i][j] != -1) {
    //         return dp[i][j];
    //     }
    //     int maxi = INT_MIN;
    //     for (int idx = i; idx <= j; idx++) {
    //         int cost = (nums[i - 1] * nums[j + 1] * nums[idx]) +
    //                    solve(nums, i, idx - 1, dp) +
    //                    solve(nums, idx + 1, j, dp);
    //         maxi = max(maxi, cost);
    //     }
    //     return dp[i][j] = maxi;
    // }
    int maxCoins(vector<int>& nums) {
        nums.push_back(1);
        nums.insert(nums.begin(), 1);
        int n = nums.size();
        vector<vector<int>> dp(n + 1, vector<int>(n + 1, 0));
        for (int i = n-2; i >= 1; i--) {
            for (int j = 1; j <=n-2; j++) {
                if (i > j) {
                    continue;
                }
                int maxi = INT_MIN;
                for (int idx = i; idx <= j; idx++) {

                    int cost = (nums[i - 1] * nums[j + 1] * nums[idx]) +
                               dp[i][idx - 1] + dp[idx + 1][j];
                    maxi = max(maxi, cost);
                }
                dp[i][j] = maxi;
            }
        }
        return dp[1][n - 2];
    }
};