class Solution {
public:
    bool solve(int idx, int count, string s) {
        if (count < 0) {
            return false;
        }
        if (idx >= s.length()) {
            return (count == 0);
        }
        if (s[idx] == '(') {
            return solve(idx + 1, count + 1, s);
        } else if (s[idx] == ')') {
            return solve(idx + 1, count - 1, s);
        }
        return solve(idx + 1, count + 1, s) or solve(idx + 1, count - 1, s) or
               solve(idx + 1, count, s);
    }
    bool checkValidString(string s) { return solve(0, 0, s); }
};