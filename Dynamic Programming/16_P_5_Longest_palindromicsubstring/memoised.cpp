class Solution {
public:
    int checkPalindrome(int i, int j, string& s, vector<vector<int>>& dp) {
        if (i >= j) {
            return 1;
        }
        if (dp[i][j] != -1) {
            return dp[i][j];
        }
        if (s[i] == s[j]) {
            return dp[i][j] = checkPalindrome(i + 1, j - 1, s, dp);
        }
        return dp[i][j] = 0;
    }
    string longestPalindrome(string s) {
        int n = s.length();
        vector<vector<int>> dp(n, vector<int>(n, -1));
        string ans;
        int maxlength = 0;
        for (int i = 0; i < n; i++) {
            for (int j = i; j < n; j++) {
                if (checkPalindrome(i, j, s, dp)) {
                    if (j - i + 1 > maxlength) {
                        maxlength = j - i + 1;
                        ans = s.substr(i, j - i + 1);
                    }
                }
            }
        }
        return ans;
    }
};