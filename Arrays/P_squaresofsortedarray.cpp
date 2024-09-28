class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        int n = nums.size();
        int i = 0, j = n - 1;
        int idx = n - 1;
        vector<int> ans(n);
        while (idx >= 0) {
            int a = nums[i];
            int b = nums[j];
            if (a * a > b * b) {
                ans[idx] = (a * a);
                idx--;
                i++;
            } else {
                ans[idx] = (b * b);
                idx--;
                j--;
            }
        }
        return ans;
    }
};