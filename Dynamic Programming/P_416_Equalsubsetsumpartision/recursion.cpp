class Solution {
public:

    bool solveRecursion(vector<int>& nums,int index,int target){
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

        // include exclude principal
        bool include=solveRecursion(nums,index+1,target-nums[index]);
        bool exclude=solveRecursion(nums,index+1,target);
        return (include||exclude);
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
        bool ans=solveRecursion(nums,index,sum/2);
        return ans;
    }
};