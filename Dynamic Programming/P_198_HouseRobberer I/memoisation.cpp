class Solution {
public:
    int solve(vector<int>& nums,int n, vector<int>& dp) {
        if (n <= 0) {
            return 0;
        }
        if (dp[n] != -1) {
            return dp[n];
        }
        // include
        int include = solve(nums, n - 2, dp) + nums[n-1];
        int exclude = solve(nums, n - 1, dp);
        return dp[n] = max(include, exclude);
    }

    int rob(vector<int>& nums) {
        int value = 0;
        int n = nums.size();
        vector<int> dp(n + 1, -1);
        return solve(nums, n, dp);
    }
};