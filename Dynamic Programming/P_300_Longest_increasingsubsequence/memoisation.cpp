class Solution {
public:
    // int ans = INT_MIN;
    int t[2501][2501];
    int solve(int prev, int i, vector<int>& nums) {
        if (i >= nums.size()) {
            return 0;
        }
        if (prev != -1 and t[i][prev] != -1) {
            return t[i][prev];
        }
        int take = 0;
        if (prev == -1 or nums[prev] < nums[i]) {

            take = solve(i, i + 1, nums) + 1;
        }
        int skip = solve(prev, i + 1, nums);
        if (prev == -1)
            return max(skip, take);
        return t[i][prev] = max(skip, take);
    }
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        // vector<vector<int>> dp(n + 1, vector<int>(n + 1, -1));
        memset(t, -1, sizeof(t));
        int prev = -1;
        int i = 0;
        return solve(prev, i, nums);
    }
};