class Solution {
public:
    string minWindow(string s, string t) {
        if (s.empty() or t.empty()) {
            return "";
        }
        int k = t.size();
        int i = 0, j = 0;
        int n = s.size();
        unordered_map<char, int> map;
        for (int i = 0; i < k; i++) {
            map[t[i]]++;
        }
        int operations = t.size();
        int minlength = INT_MAX;
        int currstart = 0;
        while (j < n) {
            if (map[s[j]] > 0) {
                operations--;
            }
            map[s[j]]--;
            //shrinking process starts
            while (operations==0) {//mistake happed here
                if (minlength>j-i+1) {
                    int currlength = j - i + 1;
                    currstart = i;
                    minlength = min(minlength, currlength);
                }
                map[s[i]]++;
                if (map[s[i]] > 0) {
                    operations++;
                }
                i++;
            }
            j++;
        }
        return (minlength == INT_MAX) ? "" : s.substr(currstart, minlength);
    }
};