class Solution {
public:
    vector<int> sortArrayByParity(vector<int> &nums) {
        int l = 0;
        int i = 0, n = nums.size(), j = n - 1;
        vector<int> temp(n);

        while (i <= j) {
            if (nums[l] % 2 == 0) {
                temp[i++] = nums[l];
            } else {
                temp[j--] = nums[l];
            }
            l++;
        }
        return temp;
    }
};

// Approach 2
class Solution {
public:
    vector<int> sortArrayByParity(vector<int> &nums) {
        int i = 0, n = nums.size(), j = 0;
        // vector<int>temp (n);

        while (i < n) {
            if (nums[i] % 2 == 0) {
                swap(nums[i], nums[j]);
                j++;
            }
            i++;
        }
        return nums;
    }
};

// Approach 3
class Solution {
public:
    static bool comparator(int a, int b) {
        return a % 2 < b % 2; // a%2 will be 0 if it's even and since we do a%2 < b%2, hence a will come first if it's even
    }

    vector<int> sortArrayByParity(vector<int> &nums) {
        sort(begin(nums), end(nums), comparator);

        return nums;
    }
};