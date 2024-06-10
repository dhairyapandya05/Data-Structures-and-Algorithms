class Solution {
public:
    void solve_dfs(int u, vector<bool>& visited,
                   unordered_map<int, vector<int>>& adj) {
        visited[u] = true;
        for (auto& v : adj[u]) {
            if (visited[v] == false) {
                solve_dfs(v, visited, adj);
            }
        }
    }
    int findCircleNum(vector<vector<int>>& isConnected) {
        int count = 0;
        unordered_map<int, vector<int>> adj;
        int n=isConnected.size();
        for (int u = 0; u < n; u++) {
            for (int v = 0; v < n; v++) {
                if (isConnected[u][v] == 1 and u!=v) {
                    adj[u+1].push_back(v+1);
                }
            }
        }
        vector<bool> visited(isConnected.size(), false);
        for (int i = 1; i <= isConnected.size(); i++) {
            if (visited[i] == false) {
                solve_dfs(i, visited, adj);
                ++count;
            }
        }
        return count;
    }
};