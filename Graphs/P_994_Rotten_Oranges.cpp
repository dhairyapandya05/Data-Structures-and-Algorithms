class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        queue<pair<int, int>> q;
        int time = 0;
        vector<pair<int, int>> directions = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};
        int n = grid.size();
        int m = grid[0].size();
        int freshoranges = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (grid[i][j] == 2)
                    q.push({i, j});
                if (grid[i][j] == 1)
                    freshoranges++;
            }
        }
        while (!q.empty() and freshoranges > 0) {
            int quen = q.size();
            while (quen--) {
                auto [tempx, tempy] = q.front();
                q.pop();
                for (auto dir : directions) {
                    int nx = tempx + dir.first;
                    int ny = tempy + dir.second;
                    if (nx >= 0 and nx < n and ny >= 0 and ny < m and
                        grid[nx][ny] == 1) {
                        grid[nx][ny] = 2; // that particular orange is rotton
                                          // now
                        q.push({nx, ny});
                        freshoranges--;
                    }
                }
            }
            time++;
        }
        cout << time << "it";
        return (freshoranges == 0) ? time : -1;
    }
};