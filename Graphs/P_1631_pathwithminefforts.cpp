class Solution {
public:
    typedef pair<int, pair<int, int>> p;
    vector<vector<int>> directions = {{0, -1}, {0, 1}, {-1, 0}, {1, 0}};
    bool isSafe(int x, int y, int n, int m) {
        return x >= 0 and x < n and y >= 0 and y < m;
    }
    int minimumEffortPath(vector<vector<int>>& heights) {
        int n = heights.size();
        int m = heights[0].size();
        vector<vector<int>> result(n, vector<int>(m, INT_MAX));
        result[0][0] = 0;
        priority_queue<p, vector<p>, greater<p>> pq;
        pq.push({0, {0, 0}});
        while (!pq.empty()) {
            auto temp = pq.top();
            pq.pop();
            int diff = temp.first;
            auto coordinate = temp.second;
            int x = coordinate.first;
            int y = coordinate.second;
            for (auto& dir : directions) {
                int _x = dir[0];
                int _y = dir[1];
                if (isSafe(x + _x, y + _y, n, m)) {
                    int absdiff = abs(heights[x][y] - heights[x + _x][y + _y]);
                    int maxdiff = max(absdiff, diff);
                    if (result[x + _x][y + _y] > maxdiff) {
                        result[x + _x][y + _y] = maxdiff;
                        pq.push({maxdiff,{x+_x,y+_y}});
                    }
                }
            }
        }
        return result[n-1][m-1];
    }
};
// link: https://leetcode.com/problems/path-with-minimum-effort/