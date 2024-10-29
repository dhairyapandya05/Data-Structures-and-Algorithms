class Solution {
public:
    int solve(vector<int>& nums, int i, int j) {
        if (i > j) {
            return 0;
        }
        int maxi = INT_MIN;
        for (int idx = i; idx <= j; idx++) {
            int cost = (nums[i - 1] * nums[j + 1] * nums[idx]) +
                       solve(nums, i, idx - 1) + solve(nums, idx + 1, j);
            maxi = max(maxi, cost);
        }
        return maxi;
    }
    int maxCoins(vector<int>& nums) {
        int n = nums.size();
        nums.push_back(1);
        nums.insert(nums.begin(), 1);
        return solve(nums, 1, n);
    }
};