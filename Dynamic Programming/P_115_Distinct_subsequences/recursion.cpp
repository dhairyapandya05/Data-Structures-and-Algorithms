class Solution {
public:
    void solve(int idx, unordered_map<char, int>& map, int& ans, string& s,
               string t, char insearchof, int t_idx) {
        if (idx >= s.length()) {
            for (auto& it : map) {
                if (it.second > 0) {
                    return;
                }
            }
            ans++;
            return;
        }
        if (s[idx] == insearchof and map[s[idx] > 0]) {
            // include case
            map[s[idx]]--;
            solve(idx + 1, map, ans, s, t, t[t_idx + 1], t_idx + 1);
            map[s[idx]]++;
            // exclude case
            solve(idx + 1, map, ans, s, t, insearchof, t_idx);
        } else {
            solve(idx + 1, map, ans, s, t, insearchof, t_idx);
        }
    }
    int numDistinct(string s, string t) {
        unordered_map<char, int> map;
        int ans = 0;
        for (auto it : t) {
            map[it]++;
        }
        solve(0, map, ans, s, t, t[0], 0);
        return ans;
    }
};