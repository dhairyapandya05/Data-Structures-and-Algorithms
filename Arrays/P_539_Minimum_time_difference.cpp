class Solution {
public:
    int findMinDifference(vector<string> &timePoints) {
        vector<int> minvector;
        for (int i = 0; i < timePoints.size(); i++) {
            string currenttime = timePoints[i];
            int hr = stoi(currenttime.substr(0, 2));
            int min = stoi(currenttime.substr(3, 2));
            int totalmin = hr * 60 + min;
            minvector.push_back(totalmin);
        }
        int n = minvector.size();
        sort(minvector.begin(), minvector.end());
        int mindifference = INT_MAX;
        for (int i = 0; i < minvector.size() - 1; i++) {
            mindifference = min(mindifference, minvector[i + 1] - minvector[i]);
        }
        return min(mindifference, (minvector[0] + 1440) - minvector[n - 1]);
    }
};