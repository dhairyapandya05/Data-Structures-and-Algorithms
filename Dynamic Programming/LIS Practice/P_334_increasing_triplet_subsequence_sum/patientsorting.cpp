class Solution {
public:
    bool increasingTriplet(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(n, 1);
        vector<int> lis;
        for (int i = 0; i < n; ++i) {
            auto lowerBound = lower_bound(lis.begin(), lis.end(), nums[i]);
            if (lowerBound == lis.end()) {
                lis.push_back(nums[i]);
            } else {
                *lowerBound = nums[i];
            }
            dp[i] = lis.size();
        }
        for (auto& it : dp) {
            if (it >= 3) {
                return true;
            }
        }
        return false;
    }
};