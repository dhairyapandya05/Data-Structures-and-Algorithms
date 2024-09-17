class Solution {
public:
    int solve(int idx,vector<int>& nums){
        if(idx>=nums.size()-1){
            return 0;
        }
        int ans=100000;
        for(int i=1;i<=nums[idx];i++){
            ans=min(ans,solve(idx+i,nums)+1);
        }
        return ans;
    }
    int jump(vector<int>& nums) {
        int idx=0;
        int steps=0;
        int ans= solve(0,nums);
        // return steps;
        return ans;
    }
};