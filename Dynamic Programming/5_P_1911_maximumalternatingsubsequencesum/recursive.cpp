class Solution {
public:
    typedef long long ll;
    ll solve(vector<int>& nums, int i, bool add_flag) { // if flag==0 we will add
        if (i >= nums.size()) {
            return 0;
        }
        ll skip = solve(nums, i + 1, add_flag);
        ll val = (add_flag) ? nums[i] : nums[i] * -1;

        ll take = solve(nums, i + 1, !add_flag) + val;
        return max(take, skip);
    }
    long long maxAlternatingSum(vector<int>& nums) {
        bool add_flag = true;
        int i = 0;
        return solve(nums, i, add_flag);
    }
};
/*

Example 1:

Input: nums = [4,2,5,3]
Output: 7
Explanation: It is optimal to choose the subsequence [4,2,5] with alternating sum (4 + 5) - 2 = 7.
Example 2:

Input: nums = [5,6,7,8]
Output: 8
Explanation: It is optimal to choose the subsequence [8] with alternating sum 8.
Example 3:

Input: nums = [6,2,1,2,4,5]
Output: 10
Explanation: It is optimal to choose the subsequence [6,1,5] with alternating sum (6 + 5) - 1 = 10.

*/