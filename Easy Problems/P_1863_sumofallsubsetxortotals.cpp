class Solution {
public:
    void solve(vector<int>& nums, int i, vector<vector<int>>& subsets,
               vector<int>& subset) {
        if (i == nums.size()) {
            subsets.push_back(subset);
            return;
        }
        subset.push_back(nums[i]);
        solve(nums, i + 1, subsets, subset);
        subset.pop_back();
        solve(nums, i + 1, subsets, subset);
    }
    int subsetXORSum(vector<int>& nums) {
        vector<vector<int>> subsets;
        vector<int> subset;
        solve(nums, 0, subsets, subset);
        int result = 0;
        for (auto& curr : subsets) {
            int xors = 0;
            for (auto& num : curr) {
                xors ^= num;
            }
            result += xors;
        }
        return result;
    }
};