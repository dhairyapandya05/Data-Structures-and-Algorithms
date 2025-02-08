class Solution {
public:
    int robotSim(vector<int> &commands, vector<vector<int>> &obstacles) {
        set<pair<int, int>> obs;
        for (auto it : obstacles) {
            obs.insert({it[0], it[1]});
        }
        vector<pair<int, int>> dir{{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
        int i = 0;
        pair<int, int> curr{0, 0};
        int maxDistSq = 0;
        for (auto it : commands) {
            if (it == -1) {
                i = (i + 1) % 4;
                continue;
            } else if (it == -2) {
                i = (i + 3) % 4;
                continue;
            } else {
                int shiftX = it * dir[i].first;
                int shiftY = it * dir[i].second;
                if (shiftX == 0) {
                    // there is movement in Y
                    int finalY = curr.second + shiftY;
                    while (curr.second != finalY) {
                        curr.second += dir[i].second;
                        if (obs.find(curr) != obs.end()) {
                            curr.second -= dir[i].second;
                            break;
                        }
                    }
                } else {
                    // there is movement in X
                    int finalX = curr.first + shiftX;
                    while (curr.first != finalX) {
                        curr.first += dir[i].first;
                        if (obs.find(curr) != obs.end()) {
                            curr.first -= dir[i].first;
                            break;
                        }
                    }
                }
            }

            maxDistSq = max(maxDistSq, curr.first * curr.first +
                                           curr.second * curr.second);
        }
        return maxDistSq;
    }
};