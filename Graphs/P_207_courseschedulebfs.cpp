class Solution {
public:
    void solve_bfs(unordered_map<int, vector<int>>& adj, vector<bool>& visited,
                   vector<int>& result, vector<int> indegree) {
        queue<int> q;
        for (int i = 0; i < indegree.size(); i++) {
            if (indegree[i] == 0) {
                q.push(i);
            }
        }

        while (!q.empty()) {
            int n = q.size();
            while (n--) {
                int temp = q.front();
                q.pop();
                visited[temp] = true;
                result.push_back(temp);
                for (auto& v : adj[temp]) {
                    indegree[v]--;
                    if (indegree[v] == 0) {
                        q.push(v);
                    }
                }
            }
        }
    }
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        unordered_map<int, vector<int>> adj;
        vector<int> indegree(numCourses, 0);

        for (auto it : prerequisites) {
            int v = it[0];
            int u = it[1];
            adj[u].push_back(v);
            indegree[v]++;
        }
        vector<bool> visited(numCourses, false);
        vector<int> result;
        // for (int i = 0; i < numCourses; i++) {
        //     if (visited[i] == false) {
                solve_bfs(adj, visited, result, indegree);
        //     }
        // }
        if (result.size() == numCourses) {
            return true;
        } else {
            return false;
        }
    }
};