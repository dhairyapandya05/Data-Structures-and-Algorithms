class Solution {
public:
    int solve(vector<int>& nums,int i,int& n, int value){
        if(i>=n){
            return value;
        }
        //include
        int include=solve(nums,i+2,n,value+nums[i]);
        int exclude=solve(nums,i+1,n,value);
        return max(include,exclude);
    }

    int rob(vector<int>& nums) {
        int value=0;
        int i=0;
        int n=nums.size();
        return solve(nums,i,n,value);
    }
};