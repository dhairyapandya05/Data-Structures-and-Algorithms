class Solution {
public:
    unordered_map<string, long long> mp;
    long long solve(int prev, int curr, vector<int>& nums) {
        if (curr >= nums.size()) {
            return 0;
        }
        string key = to_string(prev) + to_string(curr);
        if (mp.find(key) != mp.end()) {
            return mp[key];
        }
        long long int taken = INT_MIN, nottaken = INT_MIN;
        if (prev == -1 or nums[curr] - nums[prev] >= curr - prev) {
            taken = solve(curr, curr + 1, nums) + nums[curr];
        }
        nottaken = solve(prev, curr + 1, nums);
        return mp[key] = max<long long>(taken, nottaken);
    }
    long long maxBalancedSubsequenceSum(vector<int>& nums) {
        long long maxEle = *max_element(nums.begin(), nums.end());
        if (maxEle <= 0) {
            return maxEle;
        }
        long long ans = solve(-1, 0, nums);
        return ans;
    }
};