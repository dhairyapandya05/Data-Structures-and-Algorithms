class Solution {
public:
    vector<vector<int>> threeSum(vector<int> &nums) {
        int n = nums.size();
        vector<vector<int>> ans;
        sort(nums.begin(), nums.end());

        for (int i = 0; i < n - 2; i++) {
            int s = i + 1, e = n - 1;
            while (s < e) {
                if (nums[s] + nums[e] == -nums[i]) {
                    ans.push_back({nums[i], nums[s], nums[e]});
                    while (s + 1 < n && nums[s] == nums[s + 1])
                        s++;
                    while (e - 1 >= 0 && nums[e] == nums[e - 1])
                        e--;
                    s++, e--;
                } else
                    nums[s] + nums[e] > -nums[i] ? e-- : s++;
            }
            while (i + 1 < n && nums[i] == nums[i + 1])
                i++;
        }
        return ans;
    }
};