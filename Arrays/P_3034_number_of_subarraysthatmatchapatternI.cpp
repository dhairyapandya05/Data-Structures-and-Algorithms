class Solution {
public:
    int countMatchingSubarrays(vector<int> &nums, vector<int> &pattern) {
        int n = nums.size();
        int k = pattern.size();
        int count = 0;
        for (int i = 0; i <= n - k - 1; i++) {
            int j = 0;
            while (j < k) {
                if (pattern[j] == 1 and nums[i + j + 1] > nums[i + j]) {
                    j++;
                } else if (pattern[j] == 0 and nums[i + j + 1] == nums[i + j]) {
                    j++;
                } else if (pattern[j] == -1 and nums[i + j + 1] < nums[i + j]) {
                    j++;
                } else {
                    break;
                }
            }
            if (j == k) {
                count++;
            }
        }
        return count;
    }
};