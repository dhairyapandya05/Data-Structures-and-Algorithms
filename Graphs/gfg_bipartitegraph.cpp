class Solution {
public:
    bool solve(int curr, unordered_map<int, vector<int>>& adj,
               vector<int>& color, int currentcolor) {
        color[curr] = currentcolor;
        // currentcolor = 1 - currentcolor; // Toggle the color
        currentcolor=(currentcolor==1)?0:1;
        for (auto& v : adj[curr]) {
            if (color[v] == color[curr]) {
                return false;
            }
            if (color[v] == -1) {
                if (!solve(v, adj, color, currentcolor)) {
                    return false;
                }
            }
        }
        return true;
    }
    bool isBipartite(vector<vector<int>>& graph) {
        unordered_map<int, vector<int>> adj;
        int n = graph.size();
        for (int u = 0; u < n; u++) {
            for (int v : graph[u]) {
                adj[u].push_back(v);
                adj[v].push_back(u);
            }
        }
        vector<int> color(n, -1);
        int currentcolor = 0;
        for (int i = 0; i < n; i++) {
            if (color[i] == -1) {
                if (solve(i, adj, color, currentcolor) == false) {
                    return false;
                }
            }
        }
        return true;
    }
};
// link: https://www.geeksforgeeks.org/problems/bipartite-graph/1