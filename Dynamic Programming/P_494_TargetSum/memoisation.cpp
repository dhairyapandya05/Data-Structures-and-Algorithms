class Solution {
public:
    int solve(int idx,int target,vector<int>& nums,vector<vector<int>>& dp,int& sum){
        if(idx>=nums.size()){
            if(target==0){
                return 1;
            }
            else{
                return 0;
            }
        }
        // Check if the current target is out of bounds
        if (target + sum < 0 || target + sum >= dp[0].size()) {
            return 0;
        }
        if(dp[idx][target+sum]!=-1){
            return dp[idx][target+sum];
        }
        int adding=solve(idx+1,target-nums[idx],nums,dp,sum);
        int subtracting=solve(idx+1,target+nums[idx],nums,dp,sum);
        return dp[idx][target+sum]=(adding+subtracting);
    }
    int findTargetSumWays(vector<int>& nums, int target) {
        int n=nums.size();
        int sum=accumulate(nums.begin(),nums.end(),0);
        if (abs(target) > sum) return 0;
        vector<vector<int>>dp(n,vector<int>((2*sum)+1,-1));
        return solve(0,target,nums,dp,sum);
    }
};