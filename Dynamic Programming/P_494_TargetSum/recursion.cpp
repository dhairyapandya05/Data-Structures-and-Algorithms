class Solution {
public:
    int solve(int idx,int target,vector<int>& nums){
        if(idx>=nums.size()){
            if(target==0){
                return 1;
            }
            else{
                return 0;
            }
        }

        int adding=solve(idx+1,target-nums[idx],nums);
        int subtracting=solve(idx+1,target+nums[idx],nums);
        return adding+subtracting;
    }
    int findTargetSumWays(vector<int>& nums, int target) {
        return solve(0,target,nums);
    }
};