class Solution {
public:
    typedef pair<char, int> p;
    struct comp {
        bool operator()(p& p1, p& p2) {
            if (p1.first == p2.first) {
                return p2.second > p1.second;
            }
            return p1.first > p2.first;
        }
    };
    string clearStars(string s) {
        string result = "";
        priority_queue<p, vector<p>, comp> pq;
        for (int i = 0; i < s.length(); i++) {
            if (s[i] != '*')
                pq.push({s[i], i});
            else {
                char ch = pq.top().first;
                int idx = pq.top().second;
                pq.pop();
                s[idx] = '*';
            }
        }
        for (int i = 0; i < s.length(); i++) {
            if (s[i] != '*') {
                result.push_back(s[i]);
            }
        }
        return result;
    }
};