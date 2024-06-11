https://leetcode.com/problems/satisfiability-of-equality-equations/
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

    void unionsets(int u, int v) {
        int u_parent = find(u);
        int v_parent = find(v);
        if (u_parent != v_parent) {
            if (rank[u_parent] > rank[v_parent]) {
                parent[v_parent] = u_parent;
            } else if (rank[v_parent] > rank[u_parent]) {
                parent[u_parent] = v_parent;
            } else {
                parent[u_parent] = v_parent;
                rank[u_parent]++;
            }
        }
    }
    bool equationsPossible(vector<string>& equations) {
        parent.resize(26);
        rank.resize(26, 0);
        for (int i = 0; i < 26; i++) {
            parent[i] = i;
        }
        for (auto eq : equations) {
            int u = eq[0];
            int v = eq[3];

            if (eq[1] == '=') {
                unionsets(u - 'a', v - 'a');
            }
        }

        for (auto eq : equations) {
            int u = eq[0];
            int v = eq[3];
            if (eq[1] == '!') {
                int u_parent = find(u - 'a');
                int v_parent = find(v - 'a');
                if (u_parent == v_parent) {
                    return false;
                }
            }
        }
        return true;
    }
};