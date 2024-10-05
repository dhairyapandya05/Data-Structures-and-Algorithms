// its correct way of minding is as follows strivers method
class Solution {
public:
    bool solve(int idx, vector<int>& arr, int sum) {
        if (sum == 0) {
            return true;
        }
        if (idx == 0) {
            return arr[idx] == sum;
        }
        bool skip = false;
        bool take = false;
        skip = solve(idx - 1, arr, sum);
        if (sum - arr[idx] >= 0) {
            take = solve(idx - 1, arr, sum - arr[idx]);
        }
        return skip or take;
    }
    bool canPartition(vector<int>& nums) {
        int sum = accumulate(nums.begin(), nums.end(), 0);
        if (sum % 2 == 1) {
            return false;
        }
        int target = sum / 2;
        int n = nums.size();
        return solve(n - 1, nums, target);
    }
};

// Dhairya method
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