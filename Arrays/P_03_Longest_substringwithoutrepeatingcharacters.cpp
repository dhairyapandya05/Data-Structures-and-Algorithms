class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int i = 0, j = 0, n = s.length();
        int len = 0;
        vector<int> hash(256, -1);
        while (j < n) {
            if (hash[s[i]] != -1) {
                i = hash[s[j]] + 1;
            }
            hash[s[j]] = j;
            len = max(len, j - i + 1);
            j++;
        }
        return len;
    }
};