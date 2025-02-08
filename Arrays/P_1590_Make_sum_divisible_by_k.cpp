class Solution {
public:
    int minSubarray(vector<int> &nums, int p) {
        int n = nums.size();
        unordered_map<int, int> mp;
        mp[0] = -1;
        int sum = 0;
        for (int i = 0; i < n; i++) {
            sum = (sum + nums[i]) % p;
        }
        if (sum % p == 0) {
            return 0;
        }
        int currsum = 0;
        int target = sum % p;
        int minlen = n;
        for (int i = 0; i < n; i++) {
            currsum = (currsum + nums[i]) % p;
            int remin = (currsum - target + p) % p;
            if (mp.find(remin) != mp.end()) {
                minlen = min(minlen, i - mp[remin]);
            }
            mp[currsum] = i;
        }
        if (minlen == n) {
            return -1;
        }
        return minlen;
    }
};