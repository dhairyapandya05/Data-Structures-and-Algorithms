class Solution {
public:
    long long minimumReplacement(vector<int>& nums) {
        long long operations=0;
        int n=nums.size();
        int prev=nums[n-1];
        for(int i=n-2;i>=0;i--){
            int parts=nums[i]/prev;
            if(nums[i]%prev!=0){
                parts++;
            }
            operations+=(parts-1);
            prev=nums[i]/parts;
        }
        return operations;
    }
};