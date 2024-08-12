class Solution {
public:
    long long maxBalancedSubsequenceSum(vector<int>& nums) {
        int n = nums.size();
        map<int, long long> mp; // nums[i]-i,sum
        long long result = INT_MIN;
        for (int i = 0; i < n; i++) {
            auto it = mp.upper_bound(nums[i] - i);//log(n)
            long long sum = nums[i];
            if (it != mp.begin()) {
                it--;
                sum += it->second;
            }
            mp[nums[i] - i] = max(mp[nums[i] - i], sum);
            it = mp.upper_bound(nums[i] - i);
            while (it != mp.end() and it->second <= sum) {
                mp.erase(it++);
            }
            result = max(result, sum);
        }

        return result;
    }
};