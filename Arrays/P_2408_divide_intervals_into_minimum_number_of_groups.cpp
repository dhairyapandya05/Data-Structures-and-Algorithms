class Solution {
public:
    int minGroups(vector<vector<int>> &intervals) {
        priority_queue<int, vector<int>, greater<int>> pq;
        auto cmp = [&](vector<int> &v1, vector<int> &v2) {
            if (v1[0] == v2[0]) {
                return v1[1] < v2[1];
            }
            return v1[0] < v2[0];
        };
        sort(intervals.begin(), intervals.end(), cmp);
        for (auto it : intervals) {
            if (!pq.empty() and pq.top() < it[0]) {
                pq.pop();
                pq.push(it[1]);
            } else {
                pq.push(it[1]);
            }
        }
        return pq.size();
    }
};