class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(n + 1, -1);
        int curr;
        int prev2 = 0;
        int prev1 = nums[0];
        for (int i = 1; i < n; i++) {
            int temp = (i - 2 >= 0) ? prev2 : 0;
            int include = temp + nums[i];
            int exclude = prev1;
            curr = max(include, exclude);
            prev2 = prev1;
            prev1 = curr;
        }
        return prev1;
    }
};