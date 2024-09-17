class Solution {
public:
    bool canJump(vector<int>& nums) {
        if(nums.size()==1){
            return true;
        }
        int i=nums.size()-2;
        int steps=1;
        while(i>=0){
            if(nums[i]>=steps){
                i--;
                steps=1;
            }
            else{
                i--;
                steps++;
            }
        }
        if(steps<=nums[0]){
            return true;
        }
        return false;
    }
};