class Solution {
public:
    int minNumberOperations(vector<int> &target) {
        int curr = 0;
        int prev = 0;
        int result = 0;
        for (int i = 0; i < target.size(); i++) {
            curr = target[i];
            if (abs(curr) > abs(prev)) {
                result += abs(curr - prev);
            }
            prev = curr;
        }
        return result;
    }
};

// Similar to Problem 3229 please check it
class Solution {
public:
    int minNumberOperations(vector<int> &diff) {
        // vector<int> diff(nums.size());
        // for (int i = 0; i < nums.size(); i++) {
        //     diff[i] = target[i] - nums[i];
        // }
        int prev = 0;
        int curr = 0;
        long long operations = 0;
        for (int i = 0; i < diff.size(); i++) {
            curr = diff[i];
            if ((curr > 0 and prev < 0) or (curr < 0 and prev > 0)) { // we have encountered a sign change
                operations += abs(curr);
            } else if (abs(curr) > abs(prev)) {
                operations += abs(curr) - abs(prev);
            }
            prev = curr;
        }
        return operations;
    }
};