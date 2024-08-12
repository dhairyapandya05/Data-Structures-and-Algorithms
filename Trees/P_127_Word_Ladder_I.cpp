class Solution {
public:
    int ladderLength(string beginWord, string endWord,
                     vector<string>& wordList) {
        unordered_set<string> st(wordList.begin(), wordList.end());
        queue<pair<string, int>> q;
        q.push({beginWord, 1});
        st.erase(beginWord);
        while (!q.empty()) {
            string cmpword = q.front().first;
            int steps = q.front().second;
            q.pop();
            if (cmpword == endWord) {
                return steps;
            }
            for (int i = 0; i < cmpword.size(); i++) {
                char originalword = cmpword[i];
                for (char ch = 'a'; ch <= 'z'; ch++) {
                    cmpword[i] = ch;
                    if (st.find(cmpword) != st.end()) {
                        q.push({cmpword, steps + 1});
                        st.erase(cmpword);
                    }
                }
                cmpword[i] = originalword;
            }
        }
        return 0;
    }
};