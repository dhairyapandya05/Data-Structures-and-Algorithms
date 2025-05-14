#include <bits/stdc++.h>
using namespace std;
vector<vector<int>> dir = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};

bool isSafe(int x, int y, int n, int m, vector<vector<int>> &area) {
    return x >= 0 && y >= 0 && x < n && y < m && area[x][y] != 0 && area[x][y] != -1;
}
int minimumDistance(vector<vector<int>> area) {
    int n = area.size();    // number of rows
    int m = area[0].size(); // number of columns
    int steps = 0;

    queue<pair<int, int>> q;
    q.push({0, 0});
    if (area[0][0] == 0)
        return -1; // cannot start from a blocked cell
    area[0][0] = -1;

    while (!q.empty()) {
        int size = q.size();
        while (size--) {
            auto temp = q.front();
            int x = temp.first;
            int y = temp.second;
            if (area[x][y] == 9)
                return steps;
            area[x][y] = -1;
            q.pop();

            for (auto it : dir) {
                int newX = x + it[0];
                int newY = y + it[1];
                if (isSafe(newX, newY, n, m, area)) {
                    q.push({newX, newY});
                }
            }
        }
        steps++;
    }

    return -1;
}
int main() {
    vector<vector<int>> grid = {
        {1, 0, 0},
        {1, 0, 0},
        {1, 9, 1}};
    int ans = minimumDistance(grid);
    cout << "Answer is: " << ans;
    return 0;
}
