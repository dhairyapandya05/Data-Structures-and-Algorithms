class Solution {
public:
    int solve(int prev, int curr, vector<int>& nums) {
        if (curr >= nums.size()) {
            return 0;
        }
        int take = 0, skip;
        if (prev == -1 or nums[prev] < nums[curr]) {
            take = 1 + solve(curr, curr + 1, nums);
        }
        skip = solve(prev, curr + 1, nums);
        return max(take, skip);
    }
    int lengthOfLIS(vector<int>& nums) {
        int ans = solve(-1, 0, nums);
        return ans;
    }
};