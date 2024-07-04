class Solution {
public:
    // memoisation
    // int solve(int n, vector<int>& dp) {
    //     if (n == 0) return 0;
    //     if (n == 1) return 1;
    //     if (n == 2) return 1;
    //     if (dp[n] != -1) return dp[n];
    //     int ans1 = (dp[n - 1] == -1) ? solve(n - 1, dp) : dp[n - 1];
    //     int ans2 = (dp[n - 2] == -1) ? solve(n - 2, dp) : dp[n - 2];
    //     int ans3 = (dp[n - 3] == -1) ? solve(n - 3, dp) : dp[n - 3];
    //     dp[n] = ans1 + ans2 + ans3;
    //     return dp[n];
    // }
    int tribonacci(int n) {
        // memoisation
        //  if(n==0 or n==1) return n;
        //  vector<int> dp(n + 1, -1);
        //  dp[0] = 0;
        //  dp[1] = 1;
        //  dp[2] = 1;
        //  int ans = solve(n, dp);
        //  return ans;

        // bottomup approach
        // if (n == 0 or n == 1) {
        //     return n;
        // }
        // if (n == 2) {
        //     return 1;
        // }
        // vector<int> dp(n + 1, -1);
        // dp[0] = 0;
        // dp[1] = 1;
        // dp[2] = 1;
        // for (int i = 3; i <= n; i++) {
        //     dp[i]=dp[i-1]+dp[i-2]+dp[i-3];
        // }
        // return dp[n];

        // constant space complexity
        int a = 0;
        int b = 1;
        int c = 1;
        int d;
        if (n == 0 or n == 1)
            return n;
        if (n == 2) {
            return 1;
        }
        for (int i = 3; i <= n; i++) {
            d = a + b + c;
            a = b;
            b = c;
            c = d;
        }
        return d;
    }
};