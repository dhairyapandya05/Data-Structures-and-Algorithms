int minSubsetSumDifference(vector<int>& nums, int n)
{
	int sum = accumulate(nums.begin(), nums.end(), 0);
        vector<vector<bool>> dp(n, vector<bool>(sum + 1, false));
        for (int i = 0; i < n; i++) {
            dp[i][0] = true; // base cases are handled properly
        }
        if(sum>=nums[0])
        dp[0][nums[0]] = true; // base case are handled
        for (int idx = 1; idx < n; idx++) {
            for (int tempsum = 0; tempsum <= sum; tempsum++) {
                bool skip = false;
                bool take = false;
                skip = dp[idx - 1][tempsum];
                if (tempsum - nums[idx] >= 0) {
                    take = dp[idx - 1][tempsum - nums[idx]];
                }
                dp[idx][tempsum] = skip or take;
            }
        }
        int mindiff=INT_MAX;
        for(int i=0;i<=sum/2;i++){
            if(dp[n-1][i]==true){
                mindiff=min(mindiff,abs((sum-i)-i));
            }
        }
        return mindiff;
}
// Question link:https://www.naukri.com/code360/problems/partition-a-set-into-two-subsets-such-that-the-difference-of-subset-sums-is-minimum_842494?source=youtube&campaign=striver_dp_videos&utm_source=youtube&utm_medium=affiliate&utm_campaign=striver_dp_videos