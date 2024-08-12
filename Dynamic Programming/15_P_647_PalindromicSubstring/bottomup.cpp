class Solution {
public:
    int countSubstrings(string s) {
        int count = 0;
        int n = s.length();
        vector<vector<bool>> t(n, vector<bool>(n, false));
        for (int L = 1; L <= n; L++) {
            for (int i = 0; L + i - 1 < n; i++) {
                int j = L + i - 1;
                if (i == j) {
                    t[i][j] = true;
                } else if (j == i + 1) {
                    t[i][j] = (s[j] == s[i]);
                } else {
                    t[i][j] = (s[i] == s[j] and t[i + 1][j - 1]);
                }
                if (t[i][j] == true) {
                    count++;
                }
            }
        }
        return count;
    }
};