https://leetcode.com/problems/number-of-operations-to-make-network-connected/
class Solution {
public:
    vector<int> rank;
    vector<int> parent;
    int find(int u) {
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
    int makeConnected(int n, vector<vector<int>>& connections) {
        if(connections.size()<n-1){
            return -1;
        }
        rank.resize(n, 0);
        parent.resize(n);
        for (int i = 0; i < n; i++) {
            parent[i] = i;
        }
        for (auto connection : connections) {
            int u = connection[0];
            int v = connection[1];
            int u_parent = find(u);
            int v_parent = find(v);
            if (u_parent != v_parent) {
                Union(u_parent, v_parent);
                n--;
            }
        }
        return n-1;
    }
};