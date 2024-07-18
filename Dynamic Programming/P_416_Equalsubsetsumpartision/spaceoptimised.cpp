class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int sum = accumulate(nums.begin(), nums.end(), 0);

        // If the sum is odd, we cannot partition it into two equal subsets
        if (sum % 2 != 0) {
            return false;
        }

        int target = sum / 2;
        int n = nums.size();

        // Initialize the dp table
        vector<vector<bool>> dp(n + 1, vector<bool>(target + 1, false));
        vector<bool> prev(target + 1, 0);
        vector<bool> curr(target + 1, 0);

        prev[0]=1;
        curr[0]=1;

        // Fill the dp table
        for (int i = 1; i <= n; i++) {
            for (int t = 1; t <= target; t++) {
                bool include = false;
                if (t - nums[i - 1] >= 0) {
                    include = prev[t - nums[i - 1]];
                }
                bool exclude = prev[t];
                curr[t] = include || exclude;
            }
            prev=curr;
        }

        return prev[target];
    }
};