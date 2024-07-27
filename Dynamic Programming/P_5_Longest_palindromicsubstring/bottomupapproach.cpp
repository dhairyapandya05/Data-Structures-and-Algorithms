class Solution {
public:
    string longestPalindrome(string s) {
        int n = s.length();
        vector<vector<bool>> dp(n, vector<bool>(n, false));
        // string ans;
        int stratingpt = 0;
        int maxlength = 1;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (i == j) {
                    dp[i][j] = true;
                }
            }
        }
        for (int L = 2; L <= n; L++) {
            for (int i = 0; L + i - 1 < n; i++) {
                int j = L + i - 1;
                if (s[i] == s[j] and L == 2) {
                    dp[i][j] = true;
                    if (maxlength < j - i + 1) {
                        maxlength = j - i + 1;
                        stratingpt = i;
                    }
                } 
                else if (s[i] == s[j] and dp[i + 1][j - 1]) {
                    dp[i][j] = true;
                    if (maxlength < j - i + 1) {
                        maxlength = j - i + 1;
                        stratingpt = i;
                    }
                } 
                else {
                    dp[i][j] = false;
                }
            }
        }
        return s.substr(stratingpt, maxlength);
    }
};