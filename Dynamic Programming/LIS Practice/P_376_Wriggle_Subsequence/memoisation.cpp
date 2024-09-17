class Solution {
public:
    int solve(int prev, int curr, int increasing, vector<int>& nums,vector<vector<vector<int>>>& dp) {
        if (curr >= nums.size()) {
            return 0;
        }
        if(prev!=-1 and dp[prev][curr][increasing]!=-1){
            return dp[prev][curr][increasing];
        }
        int skip, take = 0;
        if (increasing == 1) {
            if (prev == -1 or nums[curr] > nums[prev]) {
                take = 1 + solve(curr, curr + 1, 1 - increasing, nums,dp);
            }
            skip = solve(prev, curr + 1, increasing, nums,dp);
        } else {
            if (prev == -1 or nums[curr] < nums[prev]) {
                take = 1 + solve(curr, curr + 1, 1 - increasing, nums,dp);
            }
            skip = solve(prev, curr + 1, increasing, nums,dp);
        }
        if(prev==-1){
            return max(take, skip);
        }
        return dp[prev][curr][increasing]=max(take, skip);
    }
    int wiggleMaxLength(vector<int>& nums) {
        int prev = -1, curr = 0;
        int increasing = 1;
        int n=nums.size();
        vector<vector<vector<int>>>dp(n+1,vector<vector<int>>(n+1,vector<int>(2,-1)));
        int positivediff = solve(prev, curr, increasing, nums,dp);
        increasing = 0;
        int negativediff = solve(prev, curr, increasing, nums,dp);
        return max(positivediff, negativediff);
    }
};