// Could also be solved woth the help of arrays check it in the arrays section also

class Solution {
public:
    int numberOfSubarrays(vector<int> &nums, int k) {
        int n = nums.size();
        int oddcount = 0;
        int prevcount = 0;
        int result = 0;
        int i = 0, j = 0;
        while (j < n) {
            if (nums[j] % 2 != 0) {
                oddcount++;
                prevcount = 0;
            }
            while (oddcount == k) {
                prevcount++;
                if (nums[i] % 2 == 1) {
                    oddcount--;
                }
                i++;
            }
            result += prevcount;
            j++;
        }
        return result;
    }
};

// This is the same sliding window code but from the Leetcode discussion section
class Solution {
public:
    int subArray(vector<int> &nums, int k) {
        int count = 0, ans = 0, start = 0, end = 0;
        int n = nums.size();
        while (end < n) {
            if (nums[end] % 2 == 1) {
                count++;
            }
            while (count > k) {
                if (nums[start] % 2 == 1) {
                    count--;
                }
                start++;
            }
            ans += end - start + 1;
            end++;
        }
        return ans;
    }
    int numberOfSubarrays(vector<int> &nums, int k) {
        return subArray(nums, k) - subArray(nums, k - 1);
    }
};