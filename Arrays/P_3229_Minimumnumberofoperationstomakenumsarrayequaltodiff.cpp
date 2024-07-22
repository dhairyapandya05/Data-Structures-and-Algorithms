class Solution {
public:
    // vector<int> getAbsoluteMaximums(const vector<vector<int>>& groups) {
    //     vector<int> maxValues;
    //     for (const auto& group : groups) {
    //         int maxVal = 0;
    //         for (int num : group) {
    //             maxVal = max(maxVal, abs(num));
    //         }
    //         maxValues.push_back(maxVal);
    //     }
    //     return maxValues;
    // }

    long long minimumOperations(vector<int>& nums, vector<int>& target) {
        vector<int> diff(nums.size());
        for (int i = 0; i < nums.size(); i++) {
            diff[i] = target[i] - nums[i];
        }
        int prev = 0;
        int curr = 0;
        long long operations = 0;
        for (int i = 0; i < diff.size(); i++) {
            curr = diff[i];
            if ((curr > 0 and prev < 0) or (curr < 0 and prev > 0)) {//we have encountered a sign change
                operations += abs(curr);
            }
            else if (abs(curr) > abs(prev)) {
                operations += abs(curr) - abs(prev);
            }
            // else{//abs(curr) < abs(prev)
                // do nothing
            // }
            prev = curr;
        }
        return operations;
    }
};