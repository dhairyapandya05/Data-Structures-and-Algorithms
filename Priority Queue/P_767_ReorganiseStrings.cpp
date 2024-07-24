class Solution {
public:
    string reorganizeString(string s) {
        vector<int> count(26, 0);
        int n = s.length();
        for (int i = 0; i < n; i++) {
            count[s[i] - 'a']++;
            if (count[s[i] - 'a'] > (n + 1) / 2) {
                return "";
            }
        }

        priority_queue<pair<int, char>> pq;
        for (char i = 'a'; i <= 'z'; i++) {
            if (count[i - 'a'] > 0) {
                pq.push({count[i - 'a'], i});
            }
        }
        string result = "";
        while (pq.size() >= 2) {
            auto p1 = pq.top();
            pq.pop();
            auto p2 = pq.top();
            pq.pop();
            char p1char = p1.second;
            char p2char = p2.second;
            result += p1char;
            result += p2char;
            int p1freq = p1.first;
            p1freq--;
            int p2freq = p2.first;
            p2freq--;
            if (p1freq > 0) {
                pq.push({p1freq,p1char});
            }
            if (p2freq > 0) {
                pq.push({p2freq,p2char});
            }
        }

        if (!pq.empty()) {
            result += pq.top().second;
        }

        return result;
    }
};