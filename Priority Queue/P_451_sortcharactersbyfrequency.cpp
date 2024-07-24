class Solution {
public:
    typedef pair<char, int> p;
    string frequencySort(string s) {
        auto cmp = [](p a, p b) { return a.second < b.second; };//maxheap kae case mae ulta hota hai.... imp

        priority_queue<p, vector<p>, decltype(cmp)> pq(cmp);
        unordered_map<char, int> map;
        int n = s.length();
        for (int i = 0; i < n; i++) {
            map[s[i]]++;
        }
        for (auto it = map.begin(); it != map.end(); it++) {
            pq.push({it->first, it->second});
        }
        string output = "";
        while (!pq.empty()) {
            auto it = pq.top();
            pq.pop();
            output.append(it.second, it.first);
        }
        return output;
    }
};