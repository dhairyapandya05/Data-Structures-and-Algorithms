// https://leetcode.com/problems/min-cost-to-connect-all-points/
class Solution {
public:
    typedef pair<int, int> pp;
    int PrimsAlgo(unordered_map<int, vector<pair<int, int>>>& adj, int& V) {
        vector<bool> visited(V, false);
        int sum = 0;
        priority_queue<pp, vector<pp>, greater<pp>> pq;
        pq.push({0, 0});
        while (!pq.empty()) {
            auto tp = pq.top();
            pq.pop();
            int w = tp.first;
            int v = tp.second;
            if (visited[v] == true) {
                continue;
            }
            visited[v] = true;
            sum += w;
            for (auto& ad : adj[v]) {
                int node = ad.second;
                int weight = ad.first;
                if (visited[node] == false) {
                    pq.push({weight, node});
                }
            }
        }
        return sum;
    }
    int minCostConnectPoints(vector<vector<int>>& points) {
        int V = points.size();
        unordered_map<int, vector<pair<int, int>>> adj;
        for (int i = 0; i < V - 1; i++) {
            for (int j = i + 1; j < V; j++) {
                int x1 = points[i][0];
                int x2 = points[j][0];
                int y1 = points[i][1];
                int y2 = points[j][1];
                int wt = abs(y2 - y1) + abs(x2 - x1);
                adj[i].push_back({wt, j});
                adj[j].push_back({wt, i});
            }
        }
        return PrimsAlgo(adj, V);
    }
};