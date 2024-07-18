class Solution {
public:
    bool solveRecursionmemo(vector<int>& nums,int index,int target,vector<vector<int>>&dp){
        // basecase
        if(target==0){
            return 1;
        }
        if(index>=nums.size()){
            return 0;
        }
        if(target<0){
            return 0;
        }    
        if(dp[index][target]!=-1){
            return dp[index][target];
        }
        bool include=solveRecursionmemo(nums,index+1,target-nums[index],dp);
        bool exclude=solveRecursionmemo(nums,index+1,target,dp); 
        dp[index][target]=include||exclude;
        return dp[index][target];

    }
    bool canPartition(vector<int>& nums) {
        int index=0;
        int sum=0;
        for(int i=0;i<nums.size();i++){
            sum+=nums[i];
        }
        if(sum&1){
            return false;
        }
        // bool ans=solveRecursion(nums,index,sum/2);
        int n=nums.size();
        vector<vector<int>> dp(n+1,vector<int>(sum,-1));
        bool ans=solveRecursionmemo(nums,index,sum/2,dp);
        return ans;
    }
};