class Solution {
public:
    vector<pair<int, int>> dir{{-1, 0}, {1, 0}, {0, 1}, {0, -1}};
    bool isSafe(int i, int j, int &n, int &m) {
        return (i >= 0 and i < n and j >= 0 and j < m);
    }
    vector<vector<int>> updateMatrix(vector<vector<int>> &mat) {
        int n = mat.size();
        int m = mat[0].size();
        vector<vector<int>> ans(n, vector<int>(m, -1));
        // vector<vector<int>> visited(n, vector<int>(m, 0));
        queue<vector<int>> qe; // structure of storing dist , (i, j) coordinates
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (mat[i][j] == 0) {
                    // visited[i][j] = 1; // marking them as visited
                    ans[i][j] = 0;
                    qe.push({i, j}); // inserting all the 0 index blocks
                                     // which is having the shortest distance
                }
            }
        }
        while (!qe.empty()) {
            int t = qe.size();
            while (t--) {
                auto it = qe.front();
                qe.pop();
                // int dist = it[0];
                int i = it[0];
                int j = it[1];
                for (auto d : dir) {
                    int x = i + d.first;
                    int y = j + d.second;
                    if (isSafe(x, y, n, m) and ans[x][y] == -1) {
                        // visited[x][y] = 1; // marking them as visited
                        ans[x][y] = ans[i][j] + 1;
                        qe.push({x, y});
                    }
                }
            }
        }

        return ans;
    }
};

// Approach 2
class Solution {
public:
    vector<pair<int, int>> dir{{-1, 0}, {1, 0}, {0, 1}, {0, -1}};
    bool isSafe(int i, int j, int &n, int &m, vector<vector<int>> &visited) {
        return (i >= 0 and i < n and j >= 0 and j < m and visited[i][j] == 0);
    }
    vector<vector<int>> updateMatrix(vector<vector<int>> &mat) {
        int n = mat.size();
        int m = mat[0].size();
        vector<vector<int>> ans(n, vector<int>(m, 100000));
        vector<vector<int>> visited(n, vector<int>(m, 0));
        queue<vector<int>> qe; // structure of storing dist , (i, j) coordinates
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (mat[i][j] == 0) {
                    visited[i][j] = 1; // marking them as visited
                    ans[i][j] = 0;
                    qe.push({0, i, j}); // inserting all the 0 index blocks
                                        // which is having the shortest distance
                }
            }
        }
        while (!qe.empty()) {
            int t = qe.size();
            while (t--) {
                auto it = qe.front();
                qe.pop();
                int dist = it[0];
                int i = it[1];
                int j = it[2];
                for (auto d : dir) {
                    int x = i + d.first;
                    int y = j + d.second;
                    if (isSafe(x, y, n, m, visited)) {
                        visited[x][y] = 1; // marking them as visited
                        ans[x][y] = min(ans[x][y], dist + 1);
                        qe.push({dist + 1, x, y});
                    }
                }
            }
        }

        return ans;
    }
};

// BFS FROM 1 TO OTHER 0's cant be used as bahut zyada time complexity ho jaigi aggar hum har ek 1 sae bfs call karae....
// har ek 1 vaalae cell sae bfs marnae sae aacha hai 0 sae bfs maarae aur har ek 1 mar minimum distance note kartae jaai