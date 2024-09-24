class Solution {
public:
    int solve(int idx, string s, unordered_set<string>& st, vector<int>& dp) {
        if (idx >= s.length()) {
            return 0;
        }
        if (dp[idx] != -1) {
            return dp[idx];
        }
        string str = "";
        int notexcluded = INT_MAX;
        for (int i = idx; i < s.length(); i++) {
            str = s.substr(idx, i - idx + 1);
            if (st.find(str) != st.end()) {
                notexcluded = min(notexcluded, solve(i + 1, s, st, dp));
            }
        }
        int excluded = 1 + solve(idx + 1, s, st, dp);
        return dp[idx] = min(notexcluded, excluded);
    }
    int minExtraChar(string s, vector<string>& dictionary) {
        int idx = 0;
        unordered_set<string> st(dictionary.begin(), dictionary.end());
        vector<int> dp(s.length() + 1, -1);
        int ans = solve(idx, s, st, dp);
        return ans;
    }
};