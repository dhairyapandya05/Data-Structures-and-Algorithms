class Solution {
public:
    int solve(int idx,vector<int>& nums,vector<int>& dp){
        if(idx>=nums.size()-1){
            return 0;
        }
        if(dp[idx]!=-1){
            return dp[idx];
        }
        int ans=100000;
        for(int i=1;i<=nums[idx];i++){
            ans=min(ans,solve(idx+i,nums,dp)+1);
        }
        return dp[idx]=ans;
    }
    int jump(vector<int>& nums) {
        int idx=0;
        int steps=0;
        vector<int> dp(nums.size(),-1);
        int ans= solve(0,nums,dp);
        return ans;
    }
};