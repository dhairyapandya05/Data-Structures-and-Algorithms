// Approach 1
class Solution {
public:
    int countServers(vector<vector<int>> &grid) {
        int n = grid.size();
        int m = grid[0].size();

        vector<int> freqRows(n, 0);
        vector<int> freqCols(m, 0);
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (grid[i][j] == 1) {
                    freqRows[i]++;
                    freqCols[j]++;
                }
            }
        }
        int cnt = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (grid[i][j] == 1 and (freqRows[i] >= 2 or freqCols[j] >= 2)) {
                    cnt++;
                }
            }
        }
        return cnt;
    }
};

// Approach 2
// Through DSU  Very good explaination must try
class DSU {
    vector<int> parent;
    vector<int> size;

public:
    DSU(int cap) {
        parent.resize(cap, 0);
        size.resize(cap, 1);
        for (int i = 0; i < cap; i++) {
            parent[i] = i;
        }
    }
    int findParent(int node) {
        if (parent[node] == node)
            return node;
        return parent[node] = findParent(parent[node]);
    }
    bool unionBySize(int a, int b) {
        a = findParent(a);
        b = findParent(b);
        if (a == b)
            return false;
        if (size[b] > size[a])
            swap(a, b);
        parent[b] = a;
        size[a] += size[b];
        return true;
    }
    int sizeEqualToTwo() {
        int cnt = 0;
        for (int i = 0; i < parent.size(); i++) {
            if (parent[i] == i and size[i] == 2) {
                cnt++;
            }
        }
        return cnt;
    }
};

class Solution {
public:
    int countServers(vector<vector<int>> &grid) {
        int n = grid.size();
        int m = grid[0].size();
        vector<int> rowHash(n);
        vector<int> colHash(m);
        DSU dsu(n + m);
        int ans = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (grid[i][j] == 1) {
                    ans++;
                    dsu.unionBySize(i, n + j);
                }
            }
        }
        cout << dsu.sizeEqualToTwo() << "\n";
        ans -= dsu.sizeEqualToTwo();
        return ans;
    }
};

// Approach 3
// Approach - 3 (Another better Approach)
// T.C : O(m*n)
// S.C : O(m+n)
class Solution {
public:
    int countServers(vector<vector<int>> &grid) {
        int m = grid.size();
        int n = grid[0].size();

        vector<int> colServerCount(n, 0);
        vector<int> RowAkelaServerCol(m, -1);

        int resultServers = 0;

        for (int row = 0; row < m; row++) {
            int countServersRow = 0;
            for (int col = 0; col < n; col++) {
                if (grid[row][col] == 1) {
                    countServersRow += 1;
                    colServerCount[col]++;
                    RowAkelaServerCol[row] = col;
                }
            }

            if (countServersRow > 1) {
                resultServers += countServersRow;
                RowAkelaServerCol[row] = -1; // no akela server in this row
            }
        }

        // Check Akela servers in each row
        for (int row = 0; row < m; row++) {
            if (RowAkelaServerCol[row] != -1) {
                int col = RowAkelaServerCol[row];
                if (colServerCount[col] > 1) {
                    resultServers += 1;
                }
            }
        }

        return resultServers;
    }
};