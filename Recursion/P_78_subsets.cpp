class Solution {
public:
    void recursionapproach(vector<int>& nums, vector<vector<int>>& ans, int i,
                           vector<int>& temp) {
        // base case
        if (i >= nums.size()) {
            ans.push_back(temp);
            return;
        }

        // include
        temp.push_back(nums[i]);
        recursionapproach(nums, ans, i + 1, temp);
        temp.pop_back();
        // exclude
        recursionapproach(nums, ans, i + 1, temp);
    }

    vector<vector<int>> subsets(vector<int>& nums) {
        int i = 0;
        vector<vector<int>> ans;
        vector<int> temp;
        recursionapproach(nums, ans, i, temp);
        return ans;
        // base case
    }
};