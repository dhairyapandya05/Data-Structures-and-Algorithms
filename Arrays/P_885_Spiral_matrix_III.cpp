class Solution {
public:
    vector<vector<int>> spiralMatrixIII(int rows, int cols, int rStart,
                                        int cStart) {
        // order of directions E S W N
        vector<pair<int, int>> dirset = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
        vector<vector<int>> ans;
        vector<int> temp;
        // temp.push_back(rStart);
        // temp.push_back(cStart);
        ans.push_back({rStart, cStart});
        int steps = 0;
        int dir = 0;
        while (ans.size() < rows * cols) {
            if (dir == 0 or dir == 2) {
                steps++;
            }
            for (int i = 0; i < steps; i++) {
                cStart = cStart + dirset[dir].second;
                rStart = rStart + dirset[dir].first;
                if (rStart >= 0 and rStart < rows and cStart >= 0 and
                    cStart < cols) {
                    ans.push_back({rStart, cStart});
                }
            }

            dir = (dir + 1) % 4;
        }
        return ans;
    }
};