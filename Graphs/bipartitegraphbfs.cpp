class Solution {
public:
    bool solvebfs(int curr, unordered_map<int, vector<int>>& adj, int currentcolor,
                  vector<int>& color) {
        queue<int> q;
        color[curr] = currentcolor;
        q.push(curr);
        while (!q.empty()) {
            int n = q.size();
            while (n--) {
                int temp = q.front();
                q.pop();
                for (auto& v : adj[temp]) {
                    if (color[v] == color[temp]) {
                        return false;
                    }
                    if (color[v] == -1) {
                        color[v] = 1 - color[temp];
                        q.push(v);
                    }
                }
            }
        }
        return true;
    }
    bool isBipartite(vector<vector<int>>& graph) {
        unordered_map<int, vector<int>> adj;
        int N = graph.size();
        for (int u = 0; u < N; u++) {
            for (auto& v : graph[u]) 
            {
                adj[u].push_back(v);
                adj[v].push_back(u);
            }
        }
        vector<int> color(N, -1);
        int currentcolor = 0;
        for (int i = 0; i < N; i++) {
            if (color[i] == -1) {
                bool ans = solvebfs(i, adj, currentcolor, color);
                if (ans == false) {
                    return false;
                }
            }
        }
        return true;
    }
};