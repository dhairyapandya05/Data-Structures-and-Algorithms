class Solution {
public:
    int rob(vector<int>& nums) {
        int value = 0;
        int i = 0;
        int n = nums.size();
        if (n == 0) {
            return 0;
        }
        if (n == 1) {
            return nums[0];
        }
        if (n == 2) {
            return max(nums[0], nums[1]);
        }
        vector<int> dp(n + 1, -1);
        // we have taken 0thidx
        int curr;
        int prev2 = 0;
        int prev1 = nums[0];
        for (int i = 1; i < n - 1; i++) {
            int temp = (i - 2 >= 0) ? prev2 : 0;
            int include = temp + nums[i];
            int exclude = prev1;
            curr = max(include, exclude);
            prev2 = prev1;
            prev1 = curr;
        }
        int ansafterthaking0thidx = prev1;


//we are not taking 0th
        prev2 = 0;
        prev1 = nums[1];
        for (int i = 2; i < n; i++) {
            int temp = (i - 2 >= 0) ? prev2 : 0;
            int include = temp + nums[i];
            int exclude = prev1;
            int curr = max(include, exclude);
            prev2 = prev1;
            prev1 = curr;
        }
        int ansafterNOTthaking0thidx = prev1;
        return max(ansafterthaking0thidx, ansafterNOTthaking0thidx);
    }
};