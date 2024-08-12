class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        int n = nums.size();
        bool onepresent = false;
        for (int i = 0; i < n; i++) {
            if (nums[i] == 1) {
                onepresent = true;
            }
            if (nums[i] <= 0 or nums[i] > n) {
                nums[i] = 1;
            }
        }
        if (onepresent == false) {
            return 1;
        }
        for (int i = 0; i < n; i++) {
            int number = abs(nums[i]);
            int idx = number - 1;
            if (nums[idx] < 0) {
                continue;
            }
            nums[idx] *= -1;
        }
        for (int i = 0; i < n; i++) {
            if (nums[i] > 0) {
                return i + 1;
            }
        }
        return n + 1;
    }
};