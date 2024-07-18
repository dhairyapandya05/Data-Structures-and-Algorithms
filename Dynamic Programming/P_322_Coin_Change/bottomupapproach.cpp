class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        vector<int> dp(amount + 1, -1);
        // int ans = solve(coins, amount, dp);
        dp[0] = 0;
        for (int target = 1; target <= amount; target++) {
            int mini = INT_MAX;
            for (int i = 0; i < coins.size(); i++) {
                if (target - coins[i] >= 0) {
                    int minians = dp[target - coins[i]];
                    if (minians != INT_MAX) {
                        mini = min(mini, minians + 1);
                    }
                }
            }
            dp[target]=mini;
        }
        return (dp[amount]==INT_MAX)?-1:dp[amount];
    }
};