class Solution {
public:
    void sortColors(vector<int>& nums) {
        int low=0;
        int high = nums.size()-1;
        // cout<<high;
        int mid=0;
        while(mid<=high){
            if(nums[mid]==0){
                //the number discovered is 0
                swap(nums[mid],nums[low]);
                low++;
                mid++;
            }

            else if(nums[mid]==1){
                mid++;
            }

            else{
                //the number discovered is 2
                swap(nums[mid],nums[high]);
                high--;
            }

        }
    }
};