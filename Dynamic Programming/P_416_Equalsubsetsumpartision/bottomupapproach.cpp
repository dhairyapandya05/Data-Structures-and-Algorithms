
// its corrrect answer is 
class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int sum = accumulate(nums.begin(), nums.end(), 0);
        if (sum % 2 == 1) {
            return false;
        }
        int target = sum / 2;
        int n = nums.size();
        vector<vector<bool>> dp(n, vector<bool>(target + 1, false));
        for (int i = 0; i < n; i++) {
            dp[i][0] = true; // base cases are handled properly
        }
        if(target>=nums[0])
        dp[0][nums[0]] = true; // base case are handled
        // return solve(n-1,arr,sum,dp);
        for (int idx = 1; idx < n; idx++) {
            for (int tempsum = 0; tempsum <= target; tempsum++) {
                bool skip = false;
                bool take = false;
                skip = dp[idx - 1][tempsum];
                if (tempsum - nums[idx] >= 0) {
                    take = dp[idx - 1][tempsum - nums[idx]];
                }
                dp[idx][tempsum] = skip or take;
            }
        }
        return dp[n - 1][target];
    }
};

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
