class Solution {
public:
    void numberofislands(vector<vector<int>> &matrix, int i, int j) {
        if (i < 0 or j < 0 or i >= matrix.size() or j >= matrix[0].size() or matrix[i][j] == 1)
            return;

        matrix[i][j] = 1; // marking them as visited
        numberofislands(matrix, i + 1, j);
        numberofislands(matrix, i - 1, j);
        numberofislands(matrix, i, j + 1);
        numberofislands(matrix, i, j - 1);
    }
    int regionsBySlashes(vector<string> &grid) {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<int>> matrix(n * 3, vector<int>(m * 3, 0));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (grid[i][j] == '/') {
                    matrix[i * 3][j * 3 + 2] = 1;
                    matrix[(i * 3) + 1][(j * 3) + 1] = 1;
                    matrix[(i * 3) + 2][j * 3] = 1;
                } else if (grid[i][j] == '\\') {
                    matrix[i * 3][j * 3] = 1;
                    matrix[(i * 3) + 1][(j * 3) + 1] = 1;
                    matrix[i * 3 + 2][(j * 3) + 2] = 1;
                }
            }
        }
        n = matrix.size();
        m = matrix[0].size();
        int cnt = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (matrix[i][j] == 0) {
                    numberofislands(matrix, i, j);
                    cnt++;
                }
            }
        }
        return cnt;
    }
};

// Approach 2 (it is not yet reviewed and analosed)
class Solution {
    vector<int> parent;
    vector<int> rank;
    int count;

public:
    int regionsBySlashes(vector<string> &grid) {
        int n = grid.size();
        int dots = n + 1;
        parent.resize(dots * dots);
        rank.resize(dots * dots, 1);
        count = 0;

        // Initialize Union-Find structure
        for (int i = 0; i < parent.size(); ++i) {
            parent[i] = i;
        }

        // Connect boundaries to the top-left corner (0,0)
        for (int i = 0; i < dots; ++i) {
            for (int j = 0; j < dots; ++j) {
                if (i == 0 || j == 0 || i == n || j == n) {
                    int cell = i * dots + j;
                    unionSets(0, cell);
                }
            }
        }

        // Process each cell and connect regions based on slashes
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                if (grid[i][j] == '\\') {
                    int cell1 = i * dots + j;
                    int cell2 = (i + 1) * dots + (j + 1);
                    unionSets(cell1, cell2);
                } else if (grid[i][j] == '/') {
                    int cell1 = (i + 1) * dots + j;
                    int cell2 = i * dots + (j + 1);
                    unionSets(cell1, cell2);
                }
            }
        }

        return count;
    }

private:
    void unionSets(int a, int b) {
        int parentA = find(a);
        int parentB = find(b);
        if (parentA == parentB) {
            count++;
        } else {
            if (rank[parentA] > rank[parentB]) {
                parent[parentB] = parentA;
            } else if (rank[parentA] < rank[parentB]) {
                parent[parentA] = parentB;
            } else {
                parent[parentB] = parentA;
                rank[parentA]++;
            }
        }
    }

    int find(int a) {
        if (parent[a] == a) {
            return a;
        }
        return parent[a] = find(parent[a]);
    }
};