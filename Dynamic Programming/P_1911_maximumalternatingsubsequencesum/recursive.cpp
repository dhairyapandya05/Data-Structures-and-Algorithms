class Solution {
public:
    typedef long long ll;
    ll solve(vector<int>& nums, int i,
             bool add_flag) { // if flag==0 we will add
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