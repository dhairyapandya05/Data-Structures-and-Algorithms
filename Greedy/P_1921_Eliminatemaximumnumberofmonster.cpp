class Solution {
public:
    int eliminateMaximum(vector<int>& dist, vector<int>& speed) {
        priority_queue<int, vector<int>, greater<int>> pq;
        for (int i = 0; i < dist.size(); i++) {
            pq.push(ceil(dist[i] / (speed[i] * 1.0)));
        }
        int t = 0;
        int cnt = 0;
        while (!pq.empty()) {
            auto it = pq.top();
            pq.pop();
            int time = it - t;
            if (time > 0) {
                cnt++;
                t++;
            } else {
                break;
            }
        }
        return cnt;
    }
};