class Solution {
public:
    int climbStairs(int n) {
        // bottom up approach
        vector<int> dp(n+1,-1);
        int prev2 = 1;
        int prev1 = 1;
        int curr;
        if (n < 2) {
            return 1;
        }
        for (int i = 2; i <= n; i++) {
            curr = prev2+prev1;
            prev2=prev1;
            prev1=curr;
        }
        return prev1;
    }
};