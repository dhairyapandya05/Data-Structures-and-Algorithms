class Solution {
public:
    // int ans = INT_MIN;
    int solve(int prev, int i, vector<int>& nums) {
        if (i >= nums.size()) {
            return 0;
        }
        int take = INT_MIN;
        int skip = solve(prev, i + 1, nums);
        if (prev < nums[i]) {
            prev=nums[i];
            take = solve(prev, i + 1, nums) + 1;
        }
        return max(skip, take);
    }
    int lengthOfLIS(vector<int>& nums) {
        int prev = INT_MIN;
        int i = 0;
        return solve(prev, i, nums);
    }
};