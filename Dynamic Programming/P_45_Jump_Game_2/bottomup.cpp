class Solution {
public:
    int jump(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(n + 1, 0);
        dp[n] = 0; // handling the base case
        for (int idx = n - 2; idx >= 0; idx--) {
            int ans = n+1;
            for (int steps = nums[idx]; steps >=1; steps--) {
                int jumps=1;
                if (idx + steps >= n) {
                    jumps = 1;
                } else {
                    jumps = 1 + dp[idx + steps];
                }
                ans = min(ans, jumps);
            }
            dp[idx] = ans;
        }
        return dp[0];
    }
};