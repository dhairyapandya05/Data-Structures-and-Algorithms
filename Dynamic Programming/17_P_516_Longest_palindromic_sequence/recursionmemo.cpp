class Solution {
public:
    int solve(string& s, int i, int j, vector<vector<int>>& dp) {
        if (i > j) {
            return 0;
        }
        if (i == j) {
            return 1;
        }
        if (dp[i][j] != -1) {
            return dp[i][j];
        }
        int ans = INT_MIN;
        if (s[i] == s[j]) {
            ans = 2 + solve(s, i + 1, j - 1, dp);
        } else {
            ans = max(solve(s, i + 1, j, dp), solve(s, i, j - 1, dp));
        }
        return dp[i][j]=ans;
    }
    int longestPalindromeSubseq(string s) {
        int n = s.length();
        vector<vector<int>> dp(n, vector<int>(n, -1));
        int ans = solve(s, 0, n - 1, dp);
        return ans;
    }
};

// other method of solving this question is by passing string s and string reverse of s in lcs function