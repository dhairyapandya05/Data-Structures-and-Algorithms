class Solution {
public:
    bool canSortArray(vector<int> &nums) {
        int n = nums.size();
        bool swapped = false;
        for (int i = 0; i < n; i++) {
            swapped = false;
            for (int j = 0; j < n - i - 1; j++) {
                if (nums[j + 1] >= nums[j]) {
                    continue;
                } else {
                    // swap is required
                    if (__builtin_popcount(nums[j]) == __builtin_popcount(nums[j + 1])) {
                        swap(nums[j], nums[j + 1]);
                        swapped = true;
                    } else {
                        // hamara previous element bada hai current element sae laekin current element ka set but != cprevious element kae set bit sae to hum usko sort nahi kar saktae , to aab direct false return karna padaega ....
                        return false;
                    }
                }
            }
            if (swapped == false) {
                break;
            }
        }
        return true;
    }
};

// Important: It is similar to bubble sort

// Approach 2 VVV Good method

class Solution {
public:
    bool canSortArray(vector<int> &nums) {
        int n = nums.size();
        int prevLarget = nums[0];
        int prevsmaller = nums[0];
        int i = 1;
        for (; i < n; i++) {
            if (__builtin_popcount(nums[i]) ==
                __builtin_popcount(nums[i - 1])) {
                prevsmaller = min(prevsmaller, nums[i]);
                prevLarget = max(prevLarget, nums[i]);
            } else {
                break;
            }
        }

        int currsmaller = (i < n) ? nums[i] : INT_MAX;
        int currlarger = (i < n) ? nums[i] : INT_MIN;
        i++;
        for (; i < n; i++) {
            if (__builtin_popcount(nums[i]) ==
                __builtin_popcount(nums[i - 1])) {
                currsmaller = min(currsmaller, nums[i]);
                currlarger = max(currlarger, nums[i]);
            } else {
                if (currsmaller < prevLarget) {
                    return false;
                }
                prevLarget = currlarger;
                prevsmaller = currsmaller;
                currsmaller = nums[i];
                currlarger = nums[i];
            }
        }
        return (currsmaller > prevLarget) ? true : false;
    }
};