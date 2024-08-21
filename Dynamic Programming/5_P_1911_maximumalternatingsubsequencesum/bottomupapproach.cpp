class Solution {
public:
    long long maxAlternatingSum(vector<int>& nums) {
        int n=nums.size();
        vector<vector<long long>> dp(n+1,vector<long long>(2,0));
        dp[0][1]=nums[0];
        dp[0][0]=0;
        for(int i=1;i<n;i++){
            dp[i][0]=max(dp[i-1][0],dp[i-1][1]-nums[i]);//even part
            dp[i][1]=max(dp[i-1][1],dp[i-1][0]+nums[i]);//odd part
        }
        return max(dp[n-1][0],dp[n-1][1]);
    }
};