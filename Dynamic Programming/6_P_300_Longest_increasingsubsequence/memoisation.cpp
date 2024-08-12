class Solution {
public:
    int solve(int prev, int curr, vector<int>& nums, vector<vector<int>>& dp) {
        if (curr >= nums.size()) {
            return 0;
        }
        if (prev != -1 and dp[prev][curr] != -1) {
            return dp[prev][curr];
        }
        int take = 0, skip;
        if (prev == -1 or nums[prev] < nums[curr]) {
            take = 1 + solve(curr, curr + 1, nums, dp);
        }
        skip = solve(prev, curr + 1, nums, dp);
        if (prev == -1) {
            return max(take, skip);
        }
        return dp[prev][curr] = max(take, skip);
    }
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> dp(n + 1, vector<int>(n + 1, -1));
        int ans = solve(-1, 0, nums, dp);
        return ans;
    }
};