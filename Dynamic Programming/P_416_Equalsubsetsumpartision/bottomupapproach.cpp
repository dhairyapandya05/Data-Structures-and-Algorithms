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

        // Base case: sum of 0 can always be achieved with 0 elements
        for (int i = 0; i <= n; i++) {
            dp[i][0] = true;
        }

        // Fill the dp table
        for (int i = 1; i <= n; i++) {
            for (int t = 1; t <= target; t++) {
                bool include = false;
                if (t - nums[i - 1] >= 0) {
                    include = dp[i - 1][t - nums[i - 1]];
                }
                bool exclude = dp[i - 1][t];
                dp[i][t] = include || exclude;
            }
        }

        return dp[n][target];
    }
};