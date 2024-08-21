class Solution {
public:
    int solve(int prev, int curr, vector<vector<int>>& envelopes) {
        if (curr >= envelopes.size()) {
            return 0;
        }
        int take = 0;
        if (prev == -1 or (envelopes[curr][0] > envelopes[prev][0] and
                           envelopes[curr][1] > envelopes[prev][1])) {
            take = 1 + solve(curr, curr + 1, envelopes);
        }
        int skip = solve(prev, curr + 1, envelopes);
        return max(skip, take);
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
        return solve(prev, curr, envelopes);
    }
};