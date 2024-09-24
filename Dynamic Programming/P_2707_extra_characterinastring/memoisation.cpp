class Solution {
public:
    int minExtraChar(string s, vector<string>& dictionary) {
        unordered_set<string> st(dictionary.begin(), dictionary.end());
        int n = s.length();
        vector<int> dp(n + 1, 0);
        for (int idx = n - 1; idx >= 0; idx--) {
            string str = "";
            int notexcluded = INT_MAX;
            for (int i = idx; i < s.length(); i++) {
                str = s.substr(idx, i - idx + 1);
                if (st.find(str) != st.end()) {
                    notexcluded = min(notexcluded, dp[i+1]);
                }
            }
            int excluded = 1 + dp[idx+1];
            dp[idx]=min(excluded,notexcluded);
        }
        return dp[0];
    }
};