class Solution {
public:
    int waysToSplitArray(vector<int> &nums) {
        long long int sum = accumulate(nums.begin(), nums.end(), 0LL);
        long long int leftSum = 0;
        long long int rightSum = 0;
        int cnt = 0;
        int n = nums.size();
        for (int i = 0; i < n - 1; i++) {
            leftSum += nums[i];
            rightSum = sum - leftSum;
            if (rightSum <= leftSum)
                cnt++;
        }
        return cnt;
    }
};