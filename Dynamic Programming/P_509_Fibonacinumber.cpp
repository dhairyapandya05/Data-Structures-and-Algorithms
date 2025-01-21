class Solution {
public:
    int solve(vector<int>& dp, int n) {
        // optional in memoisation
        // if(n==0){
        //     return 0;
        // }
        // if(n==1){
        //     return 1;
        // }
        if (dp[n] != -1) {
            return dp[n];
        }
        int ans = solve(dp, n - 1) + solve(dp, n - 2);
        dp[n] = ans;
        return dp[n];
    }

    int bottomup(int n) {
        vector<int> dp(n + 1, -1);
        dp[0] = 0;
        dp[1] = 1;
        if (n < 2) {
            return n;
        }
        for (int i=)
    }

    int fib(int n) {
        // if (n == 0) {
        //     return 0;
        // }
        // if (n == 1) {
        //     return 1;
        // }
        // return fib(n - 1) + fib(n - 2);

        // memoisation
        // if(n==0){
        //     return 0;
        // }
        // if(n==1){
        //     return 1;
        // }
        // vector<int> dp(n + 1, -1);
        // dp[0] = 0;
        // dp[1] = 1;
        // int ans=solve(dp, n);
        // return ans;

        // bottom up approach
        // vector<int> dp(n+1,-1);
        return bottomup(n);
    }
};