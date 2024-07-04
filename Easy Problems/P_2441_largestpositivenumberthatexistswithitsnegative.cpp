class Solution {
public:
    int findMaxK(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int i = 0;
        int j = nums.size() - 1;
        while (i < j) {
            if (nums[i] < 0) {
                if (abs(nums[i]) < nums[j]) {
                    j--;
                } else if (abs(nums[i]) > nums[j]) {
                    i++;
                } else {
                    return nums[j];
                }
            }
            else{
                break;
            }
        }
        return -1;
    }
};