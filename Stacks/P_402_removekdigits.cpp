class Solution {
public:
    string removeKdigits(string s, int k) {
        string result = "";
        for (int i = 0; i < s.size(); i++) {
            while (!result.empty() and k > 0 and result.back() > s[i]) {
                result.pop_back();
                k--;
            }
            if (!result.empty() or s[i] !='0') // to avoid the case when we have preceeding 0's 000045
                result.push_back(s[i]);
        }
        while (k > 0 and result.length() > 0) {
            result.pop_back();
            k--;
        }
        if (result == "") {
            return "0";
        }

        return result;
    }
};