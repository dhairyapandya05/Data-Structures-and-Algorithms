//its correct output is as follows
class Solution {
public:
    bool solve(int idx, vector<int>& arr, int sum,vector<vector<int>>& dp) {
        if (sum == 0) {
            return true;
        }
        if (idx == 0) {
            return arr[idx] == sum;
        }
        if(dp[idx][sum]!=-1){
            return dp[idx][sum];
        }
        bool skip = false;
        bool take = false;
        skip = solve(idx - 1, arr, sum,dp);
        if (sum - arr[idx] >= 0) {
            take = solve(idx - 1, arr, sum - arr[idx],dp);
        }
        return dp[idx][sum]=skip or take;
    }
    bool canPartition(vector<int>& nums) {
        int sum = accumulate(nums.begin(), nums.end(), 0);
        if (sum % 2 == 1) {
            return false;
        }
        int target = sum / 2;
        int n = nums.size();
        vector<vector<int>>dp(n,vector<int>(target+1,-1));
        return solve(n - 1, nums, target,dp);
    }
}; 


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