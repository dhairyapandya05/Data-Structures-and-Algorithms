class Solution {
public:
    int maxResult(vector<int>& nums, int idxtoremove) {
        int cnt = 0;
        int maxcnt = 0;
        for (int i = 0; i < nums.size(); i++) {
            if (i == idxtoremove) {
                continue;
            }
            if (nums[i] == 1) {
                cnt++;
                maxcnt = max(maxcnt, cnt);
            } else {
                cnt = 0;
            }
        }
        return maxcnt;
    }
    int longestSubarray(vector<int>& nums) {
        int result = 0;
        int zero = 0;
        int n=nums.size();
        for (int i = 0; i < n; i++) {
            if (nums[i] == 0) {
                zero++;
                result = max(result, maxResult(nums, i));
            }
        }
        return (zero == 0) ? n - 1 : result;
    }
};

//Approach 2 using slidong window
int longestSubarray(vector<int>& nums) {
        int n = nums.size();
        int zerocnt = 0;
        int result=0;
        int i=0;
        for (int j = 0; j < n; j++) {
            if (nums[j] == 0) {
                zerocnt++;
            }
            while (zerocnt > 1) {
                if (nums[i] == 0) {
                    zerocnt--;
                }
                i++;
            }
            result = max(result, j - i);
        }
        return result;
    }
};