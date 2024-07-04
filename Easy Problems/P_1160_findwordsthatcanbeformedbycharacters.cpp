class Solution {
public:
    int countCharacters(vector<string>& words, string chars) {
        vector<int> cmp(26, 0);
        int size = 0;
        for (auto& ch : chars) {
            cmp[ch - 'a']++;
        }
        for (auto st : words) {
            if (st.size() > chars.size()) {
                continue;
            }
            vector<int> word(26, 0);
            for (auto ch : st) {
                word[ch - 'a']++;
            }
            int sizetemp = 0;
            bool ok = true;
            for (int i = 0; i < 26; i++) {
                if (cmp[i] < word[i]) {
                    ok = false;
                    break;
                }
            }
            if (ok) {
                size += st.length();
            }
        }
        return size;
    }
};