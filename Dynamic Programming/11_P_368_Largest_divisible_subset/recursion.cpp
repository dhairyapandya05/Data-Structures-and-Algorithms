class Solution {
public:
    void solve(int idx, int prev, vector<int>& result, vector<int>& temp,
               vector<int>& nums) {
        if (idx >= nums.size()) {
            if (temp.size() > result.size()) {
                result = temp;
            }
            return;
        }
        if (prev == -1 or nums[idx] % prev == 0) {
            temp.push_back(nums[idx]);
            solve(idx + 1, nums[idx], result, temp, nums);
            temp.pop_back();
        }
        solve(idx + 1, prev, result, temp, nums);
    }
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        // recursion
        sort(nums.begin(),nums.end());
        vector<int> result;
        vector<int> temp;
        solve(0, -1, result, temp, nums);
        return result;
    }
};