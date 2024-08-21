class Solution {
public:
    int solve(int prev, int curr, vector<vector<int>>& envelopes,vector<vector<int>>& dp) {
        if (curr >= envelopes.size()) {
            return 0;
        }
        if(prev!=-1 and dp[curr][prev]!=-1){
            return dp[curr][prev];
        }
        int take = 0;
        if (prev == -1 or (envelopes[curr][0] > envelopes[prev][0] and
                           envelopes[curr][1] > envelopes[prev][1])) {
            take = 1 + solve(curr, curr + 1, envelopes,dp);
        }
        int skip = solve(prev, curr + 1, envelopes,dp);
        if(prev==-1){
            return max(skip,take);
        }
        return dp[curr][prev]=max(skip, take);
    }
    int maxEnvelopes(vector<vector<int>>& envelopes) {
        int curr = 0;
        int prev = -1;
        auto cmp=[&](vector<int>& a,vector<int>& b){
            if(a[0]==b[0]){
                return a[1]<b[1];
            }
            return a[0]<b[0];
        };
        sort(envelopes.begin(),envelopes.end(),cmp);
        int n=envelopes.size();
        vector<vector<int>>dp(n+1,vector<int>(n+1,-1));
        return solve(prev, curr, envelopes,dp);
    }
};