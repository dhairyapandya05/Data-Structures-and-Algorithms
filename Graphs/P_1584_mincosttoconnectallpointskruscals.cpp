class Solution {
public:
    vector<int> parent;
    vector<int> rank;
    int find(int& u){
        if (parent[u] == u) {
            return u;
        }
        return parent[u] = find(parent[u]);
    }

    void Union(int u, int v) {
        int u_parent = find(u);
        int v_parent = find(v);
        if (u_parent == v_parent) {
            return;
        } else {
            if (rank[u_parent] > rank[v_parent]) {
                parent[v_parent] = u_parent;
            } else if (rank[v_parent] > rank[u_parent]) {
                parent[u_parent] = v_parent;
            } else {
                parent[u_parent] = v_parent;
                rank[v_parent]++;
            }
        }
    }

    int kruskals(vector<vector<int>>& edges) {
        int sum = 0;
        for (auto& temp : edges) {
            int u = temp[0];
            int v = temp[1];
            int w = temp[2];
            int u_parent = find(u);
            int v_parent = find(v);
            if (u_parent != v_parent) {
                Union(u_parent, v_parent);
                sum += w;
            } else {
                continue;
            }
        }
        return sum;
    }

    int minCostConnectPoints(vector<vector<int>>& points) {
        int n = points.size();
        parent.resize(n);
        rank.resize(n, 0);
        for (int i = 0; i < n; i++) {
            parent[i] = i;
        }
        vector<vector<int>> edges;
        for (int i = 0; i < n - 1; i++) {
            for (int j = i + 1; j < n; j++) {
                int x1 = points[i][0];
                int y1 = points[i][1];
                int x2 = points[j][0];
                int y2 = points[j][1];
                int wt = abs(y2 - y1) + abs(x2 - x1);
                edges.push_back({i, j, wt});
            }
        }
        auto comp = [](vector<int>& v1, vector<int>& v2) {
            return v1[2] < v2[2];
        };
        sort(edges.begin(), edges.end(), comp);
        int sum = kruskals(edges);
        return sum;
    }
};