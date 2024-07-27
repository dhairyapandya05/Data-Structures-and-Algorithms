class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int maxi = 1;
        int num = 0;
        int n = nums.size();
        vector<int> t(n, 1);
        vector<int> previousidx(n, -1);
        for (int i = 1; i < n; i++) {
            for (int j = 0; j < i; j++) {
                if (nums[i] % nums[j] == 0 and t[i] < t[j] + 1) {
                    t[i] = t[j] + 1;
                    previousidx[i]=j;
                }
            }
            if (maxi < t[i]) {
                maxi = t[i];
                num = i;
            }
        }
        vector<int> finalans;
        while (maxi--) {
            finalans.push_back(nums[num]);
            num = previousidx[num];
        }
        return finalans;
    }
};