class Solution {
public:
    bool isIsomorphic(string s, string t) {
        if (s.length() != t.length()) {
            return false;
        }
        unordered_map<char, char> map;        // s->t sae map hua hai ya nahi
        unordered_map<char, char> map_t_to_s; // t->s sae map hua hai ya nahi
        for (int i = 0; i < s.length(); i++) {
            if (map.find(s[i]) == map.end() and
                map_t_to_s.find(t[i]) == map_t_to_s.end()) {
                map[s[i]] = t[i];
                map_t_to_s[t[i]] = s[i];

            } else {
                if (map[s[i]] != t[i]) {
                    return false;
                }
            }
        }
        return true;
    }
};