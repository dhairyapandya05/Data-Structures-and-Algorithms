class Solution {
public:
    int minSwaps(vector<int>& nums) {
        int totalone = accumulate(nums.begin(), nums.end(), 0);
        int k = totalone; // window size
        int maxone = 0;
        int tempone=0;
        int i = 0, j = 0;
        int n=nums.size();
        while (j<2*n){
            if(j-i+1>k){
                tempone-=nums[i%n];
                i++;
            }
            tempone+=nums[j%n];
            maxone=max(maxone,tempone);
            j++;
        }
        return totalone-maxone;
    }
};