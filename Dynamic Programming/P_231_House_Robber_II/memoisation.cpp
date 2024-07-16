class Solution {
public:
    int solve(vector<int>& nums, int i, int n, vector<int>& dp) {
        if (i > n) {
            return 0;
        }
        if (dp[i] != -1) {
            return dp[i];
        }
        // include
        int include = solve(nums, i + 2, n, dp) + nums[i];
        // exclude
        int exclude = solve(nums, i + 1, n, dp);
        return dp[i] = max(include, exclude);
    }
    int rob(vector<int>& nums) {
        int value = 0;
        int i = 0;
        int n = nums.size();
        if (n == 0) {
            return 0;
        }
        if (n == 1) {
            return nums[0];
        }
        if (n == 2) {
            return max(nums[0], nums[1]);
        }
        // case 1 if we are robbing the 0th idx house so we will not rob the
        // last idx house
        vector<int> dp(n + 1, -1);
        int zerothidx = solve(nums, 0, n - 2, dp);
        vector<int> dp1(n + 1, -1);
        int firstidx = solve(nums, 1, n - 1, dp1);
        return max(zerothidx, firstidx);
    }
};