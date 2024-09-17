class Solution {
public:
    int solve(int prev, int curr, int increasing, vector<int>& nums) {
        if (curr >= nums.size()) {
            return 0;
        }
        int skip, take = 0;
        if (increasing == 1) {
            if (prev == -1 or nums[curr] > nums[prev]) {
                take = 1 + solve(curr, curr + 1, 1 - increasing, nums);
            }
            skip = solve(prev, curr + 1, increasing, nums);
        } else {
            if (prev == -1 or nums[curr] < nums[prev]) {
                take = 1 + solve(curr, curr + 1, 1 - increasing, nums);
            }
            skip = solve(prev, curr + 1, increasing, nums);
        }
        return max(take, skip);
    }
    int wiggleMaxLength(vector<int>& nums) {
        int prev = -1, curr = 0;
        int increasing = 1;
        int positivediff = solve(prev, curr, increasing, nums);
        increasing = 0;
        int negativediff = solve(prev, curr, increasing, nums);
        return max(positivediff, negativediff);
    }
};