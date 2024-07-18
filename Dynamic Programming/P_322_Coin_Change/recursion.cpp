class Solution {
public:
    int solve(vector<int>& coins, int amount) {
        if (amount == 0) {
            return 0;
        }
        if (amount < 0) {
            return INT_MAX;
        }
        int mini = INT_MAX;

        for (int i = 0; i < coins.size(); i++) {
            int minians = solve(coins, amount - coins[i]);
            if (minians != INT_MAX) {
                mini = min(mini, minians + 1);
            }
        }
        return mini;
    }
    int coinChange(vector<int>& coins, int amount) {
        int ans = solve(coins, amount);
        return (ans == INT_MAX) ? -1 : ans;
    }
};