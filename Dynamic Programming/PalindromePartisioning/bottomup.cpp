class Solution {
public:
    vector<vector<string>> ans;
    void solve(int idx, string& s, vector<vector<bool>>& dp,
               vector<string>& temp, int& n) {
        if (idx >= n) {
            ans.push_back(temp);
        }
        for (int j = idx; j < n; j++) {
            if (dp[idx][j] == true) {
                temp.push_back(s.substr(idx, j - idx + 1));
                solve(j + 1, s, dp, temp, n);
                temp.pop_back();
            }
        }
    }
    vector<vector<string>> partition(string s) {
        int n = s.length();
        vector<vector<bool>> dp(n, vector<bool>(n, false));
        for (int i = 0; i < n; i++) {
            dp[i][i] = true;
        }

        for (int L = 2; L <= n; L++) {
            for (int i = 0; i + L - 1 < n; i++) {
                int j = i + L - 1;
                if (s[i] == s[j]) {
                    if (L == 2) {
                        dp[i][j] = true;
                    } else {
                        dp[i][j] = dp[i + 1][j - 1];
                    }
                }
            }
        }
        vector<string> temp;
        solve(0, s, dp, temp, n);
        return ans;
    }
};