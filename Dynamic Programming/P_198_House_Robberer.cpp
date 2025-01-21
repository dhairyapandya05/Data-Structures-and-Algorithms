class Solution {
public:
    // int solve(vector<int>& nums,int i,int value){
    //     if(i>=nums.size()){
    //         return value;
    //     }
    //     int include=solve(nums,i+2,value + nums[i]);
    //     int exclude=solve(nums,i+1,value);
    //     return max(include,exclude);
    // }
    // int solveMemo(vector<int>& nums,int n,vector<int>& dp){
    //     if(n<0){
    //         return 0;
    //     }
    //     if(n==0){
    //         return nums[0];
    //     }
    //     if(dp[n]!=-1){
    //         return dp[n];
    //     }
    //     int include=solveMemo(nums,n-2,dp)+ nums[n];
    //     int exclude=solveMemo(nums,n-1,dp);
    //     dp[n]= max(include,exclude);
    //     return dp[n];
    // }
    // int solveTablution(vector<int>& nums) {
    //     vector<int> dp(nums.size(), -1);
    //     dp[0] = nums[0];

    //     for (int i = 1; i <nums.size(); i++) {
    //         int temp = 0;
    //         if (i - 2 >= 0) {
    //             temp = dp[i - 2];
    //         }
    //         int include = temp + nums[i];
    //         int exclude = dp[i - 1];
    //         dp[i] = max(include, exclude);
    //     }
    //     return dp[nums.size()-1];
    // }

    int solveTablutionSO(vector<int>& nums) {
        vector<int> dp(nums.size(), -1);
        int prev2=0;
        int prev1=nums[0];
        int curr;
        // dp[0] = nums[0];

        for (int i = 1; i <nums.size(); i++) {
            int temp = 0;
            if (i - 2 >= 0) {
                temp = prev2;
            }
            int include = temp + nums[i];
            int exclude = prev1;
            curr = max(include, exclude);
            prev2=prev1;
            prev1=curr;
        }
        return prev1;;
    }
    int rob(vector<int>& nums) {
        int i = 0;
        int value = 0;
        // int n=nums.size()-1;
        int ans = solveTablutionSO(nums);
        return ans;
    }
    // formula int val=max(nums[include case],nums[exclude case])
};