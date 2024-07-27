class Solution {
public:
    bool checkPalindrome(int i, int j, string& s) {
        if (i >= j) {
            return true;
        }
        if (s[i] == s[j]) {
            return checkPalindrome(i + 1, j - 1, s);
        }
        return false;
    }
    string longestPalindrome(string s) {
        int n = s.length();
        string ans;
        int maxlength = 0;
        for (int i = 0; i < n; i++) {
            for (int j = i; j < n; j++) {
                if (checkPalindrome(i, j, s)) {
                    if (j - i + 1 > maxlength) {
                        maxlength = j - i + 1;
                        ans = s.substr(i, j-i+1);
                    }
                }
            }
        }
        return ans;
    }
};