class Solution {
public:
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
        vector<int> dp(n + 1, -1);
        // we have taken 0thidx
        dp[0] = nums[0];
        for (int i = 1; i < n - 1; i++) {
            int temp = (i - 2 >= 0) ? dp[i - 2] : 0;
            int include = temp + nums[i];
            int exclude = dp[i - 1];
            dp[i] = max(include, exclude);
        }
        int ansafterthaking0thidx = dp[n - 2];

        dp.resize(n + 1, -1);
        dp[0]=0;// to mark that we are not taking
        for (int i = 1; i < n ; i++) {
            int temp = (i - 2 >= 0) ? dp[i - 2] : 0;
            int include = temp + nums[i];
            int exclude = dp[i - 1];
            dp[i] = max(include, exclude);
        }
        int ansafterNOTthaking0thidx = dp[n - 1];
        return max(ansafterthaking0thidx, ansafterNOTthaking0thidx);
    }
};