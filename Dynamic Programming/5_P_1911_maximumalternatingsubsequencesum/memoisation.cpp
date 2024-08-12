// class Solution {
// public:
//     typedef long long ll;
//     ll t[1000001][2];
//     ll solve(vector<int>& nums, int i,
//              bool add_flag) { // if flag==0 we will add
//         if (i >= nums.size()) {
//             return 0;
//         }
//         if (t[i][add_flag] != -1) {
//             return t[i][add_flag];
//         }
//         ll skip = solve(nums, i + 1, add_flag);
//         ll val = (add_flag) ? nums[i] : nums[i] * -1;

//         ll take = solve(nums, i + 1, !add_flag) + val;
//         return t[i][add_flag] = max(take, skip);
//     }
//     long long maxAlternatingSum(vector<int>& nums) {
//         memset(t, -1, sizeof(t));
//         bool add_flag = true;
//         int i = 0;
//         return solve(nums, i, add_flag);
//     }
// };
class Solution {
public:
    typedef long long ll;
    ll solve(vector<int>& nums, int i,int add_flag,vector<vector<ll>>& dp) { // if flag==0 we will add
        if (i >= nums.size()) {
            return 0;
        }
        if (dp[i][add_flag] != -1) {
            return dp[i][add_flag];
        }
        ll skip = solve(nums, i + 1, add_flag,dp);
        ll val = (add_flag) ? nums[i] : nums[i] * -1;

        ll take = solve(nums, i + 1, 1-add_flag,dp) + val;
        return dp[i][add_flag] = max(take, skip);
    }
    long long maxAlternatingSum(vector<int>& nums) {
        int n=nums.size();
        vector<vector<ll>> dp(n+1,vector<ll>(2,-1));
        int add_flag = 1;
        int i = 0;
        return solve(nums, i, add_flag,dp);
    }
};
// the dp formed 
// The answer is 7

// -1 7 
// 3 5 
// 0 5 
// 0 3 
// -1 -1 
// vector<int> nums={4,2,5,3};