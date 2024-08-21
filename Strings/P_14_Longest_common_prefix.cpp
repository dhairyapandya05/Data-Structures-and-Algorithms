class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        int n = strs.size();
        string cmpstring = strs[0];
        string ans;
        bool match = true;
        for (int i = 0; i < cmpstring.length(); i++) {
            char ch = cmpstring[i];
            for (int j = 1; j < n; j++) {
                if (i > strs[j].length() or strs[j][i] != ch) {
                    match = false;
                    break;
                }
            }
            if (match == false) {
                break;
            } else {
                ans.push_back(ch);
            }
        }
        return ans;
    }
};