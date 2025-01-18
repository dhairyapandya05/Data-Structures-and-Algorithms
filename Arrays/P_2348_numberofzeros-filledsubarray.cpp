class Solution {
public:
    long long zeroFilledSubarray(vector<int> &nums) {
        long long ans = 0;
        int n = nums.size();
        for (int i = 0; i < n;) {
            long long l = 0;
            if (nums[i] == 0) {
                while (i < n and nums[i] == 0) {
                    i++;
                    l++;
                }
            } else {
                i++;
            }
            ans += ((l) * (l + 1) / 2);
        }
        return ans;
    }
};

// Number of subarrays possible n* (n+1)/2

// Approach 2
class Solution {
public:
    long long zeroFilledSubarray(vector<int> &nums) {
        long long ans = 0;
        int n = nums.size();
        long long int cnt = 0;
        for (int i = 0; i < n; i++) {
            if (nums[i] == 0) {
                cnt++;
            } else {
                cnt = 0;
            }
            ans += cnt;
        }
        return ans;
    }
};