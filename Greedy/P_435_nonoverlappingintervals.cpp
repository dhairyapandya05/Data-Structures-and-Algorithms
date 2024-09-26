class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        auto cmp = [&](vector<int>& v1, vector<int>& v2) {
            if (v1[1] == v2[1]) {
                return v1[0] < v2[0];
            }
            return v1[1] < v2[1];
        };
        sort(intervals.begin(), intervals.end(), cmp);
        int endingtime = INT_MIN;
        int n = intervals.size();
        int cnt = 0;
        for (int i = 0; i < n; i++) {
            if (endingtime <= intervals[i][0]) {
                cnt++;
                endingtime = intervals[i][1];
            }
        }
        return n - cnt;
    }
};