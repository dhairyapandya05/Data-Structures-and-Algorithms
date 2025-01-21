class Solution {
public:
    // int climbstair(int n, vector<int>& dp) {
    //     if (n == 0 || n == 1) {
    //         return 1;
    //     }
    //     if (dp[n] != -1) {
    //         return dp[n];
    //     }
    //     // memoisation
    //     dp[n] = climbstair(n - 1, dp) + climbstair(n - 2, dp);
    //     return dp[n];
    // }
    int climbStairs(int n) {
        // vector<int> dp(n+2,-1);
        // int ans = climbstair(n,dp);
        // return ans;

        // bottom up approach
        // vector<int> dp(n + 1, -1);
        // dp[0] = 1;
        // dp[1] = 1;
        // for (int i = 2; i <= n; i++) {
        //     dp[i] = dp[i - 1] + dp[i - 2];
        // }
        // return dp[n];
        //space optimisation
        // vector<int> dp(n + 1, -1);
        int prev1 = 1;
        int prev2 = 1;
        int curr;
        if(n<2){
            return prev1;
        }
        for (int i = 2; i <= n; i++) {
            curr = prev1 + prev2;
            prev2=prev1;
            prev1=curr;
        }
        return curr;
    }
};