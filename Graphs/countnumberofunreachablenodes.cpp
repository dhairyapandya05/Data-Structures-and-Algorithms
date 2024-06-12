// https://leetcode.com/problems/count-unreachable-pairs-of-nodes-in-an-undirected-graph/
class Solution {
public:
    vector<int> parent;
    vector<int> rank;
    int find(int u) {
        if (parent[u] == u) {
            return u;
        }
        return parent[u] = find(parent[u]);
    }

    void Unionsets(int u, int v) {
        int u_parent = find(u);
        int v_parent = find(v);
        if (u_parent == v_parent) {
            return;
        }
        if (rank[u_parent] > rank[v_parent]) {
            parent[v_parent] = u_parent;
        } else if (rank[v_parent] > rank[u_parent]) {
            parent[u_parent] = v_parent;
        } else {
            parent[u_parent] = v_parent;
            rank[v_parent]++;
        }
    }

    long long countPairs(int n, vector<vector<int>>& edges) {
        parent.resize(n);
        rank.resize(n, 0);

        for (int i = 0; i < n; i++) {
            parent[i] = i;
        }
        for (auto& edge : edges) {
            int u_parent = find(edge[0]);
            int v_parent = find(edge[1]);
            if (u_parent != v_parent) {
                Unionsets(u_parent, v_parent);
            }
        }

        unordered_map<int, int> cmps;
        for (int i = 0; i < n; i++) {
            int iParent = find(i);
            cmps[iParent]++;
        }

        long long result=0;
        long long remainingNodes = n;
        for (auto& i : cmps) {
            long long size = i.second;
            result += size * (remainingNodes - size);
            remainingNodes-=size;
        }
        return result;
    }
};