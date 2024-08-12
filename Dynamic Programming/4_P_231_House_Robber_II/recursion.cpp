class Solution {
public:
    int solve(vector<int>& nums, int i, int n, int value) {
        if (i > n) {
            return value;
        }
        // include
        int include = solve(nums, i + 2, n, value + nums[i]);
        int exclude = solve(nums, i + 1, n, value);
        return max(include, exclude);
    }
    int rob(vector<int>& nums) {
        int value = 0;
        int i = 0;
        int n = nums.size();
        if(n==0){
            return 0;
        }
        if(n==1){
            return nums[0];
        }
        if(n==2){
            return max(nums[0],nums[1]);
        }
        //case 1 if we are robbing the 0th idx house so we will not rob the last idx house
        int zerothidx=solve(nums, 0, n-2, value);
        int firstidx=solve(nums, 1, n-1, value);
        return max(zerothidx,firstidx);
    }
};