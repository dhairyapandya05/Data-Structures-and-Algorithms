class Solution {
public:
    bool hascycle;
    void solve(int u, unordered_map<int, vector<int>>& adj,
               vector<bool>& visited, vector<bool>& inRecursion,
               stack<int>& st) {
        visited[u] = true;
        inRecursion[u] = true;
        for (auto& v : adj[u]) {
            if (visited[v] == false) {
                solve(v, adj, visited, inRecursion, st);
            } else {
                if (inRecursion[v] == true) {
                    hascycle = true;
                }
            }
        }
        st.push(u);
        inRecursion[u] = false;
    }
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        unordered_map<int, vector<int>> adj;
        vector<bool> visited(numCourses, false);
        vector<bool> inRecursion(numCourses, false);
        hascycle = false;
        stack<int> st;
        vector<int> result;
        for (auto temp : prerequisites) {
            int u = temp[1];
            int v = temp[0];
            adj[u].push_back(v);
        }
        for (int i = 0; i < numCourses; i++) {
            if (visited[i] == false) {
                solve(i, adj, visited, inRecursion, st);
            }
        }
        if (hascycle == true) {
            return {};
        } else {
            while (!st.empty()) {
                result.push_back(st.top());
                st.pop();
            }
        }
        return result;
    }
};