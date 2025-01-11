class Solution {
public:
    int pivotIndex(vector<int> &nums) {
        int lsum = 0, rsum = accumulate(nums.begin(), nums.end(), 0);
        int n = nums.size();
        for (int i = 0; i < n; i++) {
            rsum -= nums[i];
            if (lsum == rsum) {
                return i;
            }
            lsum += nums[i];
        }
        return -1;
    }
};