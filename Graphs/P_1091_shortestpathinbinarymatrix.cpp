class Solution {
public:
    bool isSafe(int x, int y, int n) {
        return x >= 0 and x < n and y >= 0 and y < n;
    }
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int n = grid.size();
        vector<vector<int>> direction{{-1, 0}, {-1, -1}, {-1, 1}, {0, -1},
                                      {0, 1},  {1, -1},  {1, 0},  {1, 1}};
        queue<pair<int, int>> q;
        if (grid[0][0] == 1 or n==0) {
            return -1;
        }
        q.push({0, 0});
        grid[0][0] = 1;
        int level = 1;
        while (!q.empty()) {
            int N = q.size();
            while (N--) {
                auto it = q.front();
                q.pop();
                int _x = it.first;
                int _y = it.second;
                if (_x == n - 1 and _y == n - 1) {
                    return level;
                }
                for (auto& d : direction) {
                    int x = d[0];
                    int y = d[1];
                    if (isSafe(_x + x, _y + y, n) and
                        grid[_x + x][_y + y] == 0) {
                        q.push({_x + x, _y + y});
                        grid[_x + x][_y + y] = 1;// marking the co ordinates as visited
                    }
                }
            }
            level++;
        }
        return -1;
    }
};
// bfs
// link:https://leetcode.com/problems/shortest-path-in-binary-matrix/

// Method2 through dijkstras algorithm
class Solution {
public:
    typedef pair<int, pair<int, int>> pp;
    vector<vector<int>> directions = {
        {-1, -1}, {-1, 0}, {-1, 1}, {0, -1}, {0, 1}, {1, -1}, {1, 0}, {1, 1}};
    bool isSafe(int x, int y, int n) {
        return x >= 0 and y >= 0 and x < n and y < n;
    }
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int n = grid.size();
        vector<vector<int>> result(n,vector<int> (n,INT_MAX));
        if (n == 0 or grid[0][0] == 1 or grid[n-1][n-1]==1) {
            return -1;
        }
        priority_queue<pp, vector<pp>, greater<pp>> pq;
        pq.push({0, {0, 0}});
        grid[0][0] = 1;
        result[0][0]=0;
        while (!pq.empty()) {
            int N = pq.size();
            while (N--) {
                auto temp = pq.top();
                int w = temp.first;
                auto coordinate = temp.second;
                int x = coordinate.first;
                int y = coordinate.second;
                pq.pop();
                for (auto& direction : directions) {
                    int _x = direction[0];
                    int _y = direction[1];
                    if (isSafe(x + _x, y + _y, n) and // important first we will have to checkwhether the box that we are going to is safe or not
                        grid[x + _x][y + _y] == 0 and
                        result[x + _x][y + _y] > w + 1) {
                        pq.push({w + 1, {x + _x, y + _y}});
                        grid[x + _x][y + _y] = 1;
                        result[x + _x][y + _y] = w + 1;
                    }
                }
            }
        }
        if(result[n-1][n-1] == INT_MAX)
            return -1;
        
        return result[n-1][n-1]+1;
    }
};

// Approach 3
// Could also be solved using normal queue as the weights are same
class Solution {
public:
    typedef pair<int, pair<int, int>> pp;
    vector<vector<int>> directions = {
        {-1, -1}, {-1, 0}, {-1, 1}, {0, -1}, {0, 1}, {1, -1}, {1, 0}, {1, 1}};
    bool isSafe(int x, int y, int n) {
        return x >= 0 and y >= 0 and x < n and y < n;
    }
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int n = grid.size();
        vector<vector<int>> result(n,vector<int> (n,INT_MAX));
        if (n == 0 or grid[0][0] == 1 or grid[n-1][n-1]==1) {
            return -1;
        }
        queue<pp> pq;
        pq.push({0, {0, 0}});
        grid[0][0] = 1;
        result[0][0]=0;
        while (!pq.empty()) {
            int N = pq.size();
            while (N--) {
                auto temp = pq.front();
                int w = temp.first;
                auto coordinate = temp.second;
                int x = coordinate.first;
                int y = coordinate.second;
                pq.pop();
                for (auto& direction : directions) {
                    int _x = direction[0];
                    int _y = direction[1];
                    if (isSafe(x + _x, y + _y, n) and // important first we will have to checkwhether the box that we are going to is safe or not
                        grid[x + _x][y + _y] == 0 and
                        result[x + _x][y + _y] > w + 1) {
                        pq.push({w + 1, {x + _x, y + _y}});
                        grid[x + _x][y + _y] = 1;
                        result[x + _x][y + _y] = w + 1;
                    }
                }
            }
        }
        if(result[n-1][n-1] == INT_MAX)
            return -1;
        
        return result[n-1][n-1]+1;
    }
};
// link:https://leetcode.com/problems/shortest-path-in-binary-matrix/description/