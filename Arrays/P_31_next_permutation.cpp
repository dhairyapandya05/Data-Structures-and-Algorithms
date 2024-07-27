class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int golaidx = -1;
        int n = nums.size();
        for (int i = n - 1; i > 0; i--) {
            if (nums[i] > nums[i - 1]) {
                golaidx = i - 1;
                break;
            }
        }
        // now we have found the gola idx
        //  now we will look for the number to be reversed
        if (golaidx != -1) {
            for (int i = n - 1; i >= golaidx+1; i--) {
                if (nums[i] > nums[golaidx]) {
                    swap(nums[i], nums[golaidx]);
                    break;
                }
            }
        }
        reverse(nums.begin() + golaidx + 1, nums.end());
    }
};