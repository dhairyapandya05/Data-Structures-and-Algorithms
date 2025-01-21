class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>> &intervals) {
        auto cmp = [&](vector<int> &v1, vector<int> &v2) {
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

// Approach 2
// Approach-1
class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>> &intervals) {
        sort(begin(intervals), end(intervals));
        int n = intervals.size();

        int count = 0;
        int i = 0, j = 1;

        while (j < n) {
            vector<int> curr_interval = intervals[i];
            vector<int> next_interval = intervals[j];

            int curr_start = curr_interval[0];
            int curr_end = curr_interval[1];

            int next_start = next_interval[0];
            int next_end = next_interval[1];

            if (curr_end <= next_start) { // SAFE
                i = j;
                j++;
            } else if (curr_end <= next_end) {
                /*
                    GREEDY : Remove next interval as it has high chances to
                             overlap with future intervals
                */
                j++;
                count++;
            } else if (curr_end > next_end) {
                /*
                    GREEDY : Remove current interval as it has high chances to
                             overlap with future intervals
                */
                i = j;
                j++;
                count++;
            }
        }

        return count;
    }
};

// Similar problems: 252,253,452,2446
