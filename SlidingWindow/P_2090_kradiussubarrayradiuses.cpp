class Solution {
public:
    vector<int> getAverages(vector<int>& nums, int k) {
        int leftptr = 0;
        int rightptr = 2 * k;
        vector<int> result(nums.size(), -1);
        if (nums.size() <= 2 * k) {
            return result;
        }
        int i = k;
        long long int sum = 0;
        for (int i = 0; i <= rightptr; i++) {
            sum += nums[i];
        }
        result[i] = sum / ((2 * k) + 1);
        while (rightptr + 1 < nums.size()) {
            rightptr++;
            sum -= nums[leftptr];
            sum += nums[rightptr];
            leftptr++;
            i++;
            result[i] = sum / ((2 * k) + 1);
        }
        return result;
    }
};