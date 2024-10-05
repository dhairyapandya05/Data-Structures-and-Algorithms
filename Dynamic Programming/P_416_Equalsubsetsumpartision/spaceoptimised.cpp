// space optimised code 
class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int sum = accumulate(nums.begin(), nums.end(), 0);
        if (sum % 2 == 1) {
            return false;
        }
        int target = sum / 2;
        int n = nums.size();
        // vector<vector<bool>> dp(n, vector<bool>(target + 1, false));
        // for (int i = 0; i < n; i++) {
        //     dp[i][0] = true; // base cases are handled properly
        // }
        vector<bool>prev(target+1,false);
        vector<bool>curr(target+1);
        prev[0]=true;
        curr[0]=true;
        if(target>=nums[0])
        prev[nums[0]] = true; // base case are handled
        // return solve(n-1,arr,sum,dp);
        for (int idx = 1; idx < n; idx++) {
            for (int tempsum = 0; tempsum <= target; tempsum++) {
                bool skip = false;
                bool take = false;
                skip = prev[tempsum];
                if (tempsum - nums[idx] >= 0) {
                    take = prev[tempsum - nums[idx]];
                }
                curr[tempsum] = skip or take;
            }
            prev=curr;
        }
        return prev[target];
    }
};

// Dhairy's code 
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