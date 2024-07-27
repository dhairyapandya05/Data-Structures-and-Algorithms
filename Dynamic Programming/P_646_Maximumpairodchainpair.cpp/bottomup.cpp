class Solution {
public:
    int findLongestChain(vector<vector<int>>& nums) {
        sort(begin(nums), end(nums));
        int n = nums.size();
        vector<int> t(n, 1);
        int maxlis = 1;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < i; j++) {
                if (nums[j][1] < nums[i][0]) {
                    t[i] = max(t[j] + 1, t[i]);
                    maxlis = max(maxlis, t[i]);
                }
            }
        }
        return maxlis;
    }
};
// same as lis