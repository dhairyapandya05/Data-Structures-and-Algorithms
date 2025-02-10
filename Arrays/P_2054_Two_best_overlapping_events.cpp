class Solution {
public:
    int t[100001][3];
    int findnxtvalididx(vector<vector<int>> &events, int &endingtimeidx) {
        int endingtime = events[endingtimeidx][1];
        int s = endingtimeidx + 1;
        int n = events.size();
        int e = n - 1;
        int result = n;
        while (s <= e) {
            int mid = s + ((e - s) >> 1);
            if (events[mid][0] > endingtime) {
                result = mid;
                e = mid - 1;
            } else
                s = mid + 1;
        }
        return result;
    }
    int solve(int i, int cnt, vector<vector<int>> &events) {
        if (i == events.size() or cnt == 2)
            return 0;
        if (t[i][cnt] != -1)
            return t[i][cnt];
        int nextvalididx = findnxtvalididx(events, i);
        int take = events[i][2] + solve(nextvalididx, cnt + 1, events);
        int skip = solve(i + 1, cnt, events);
        return t[i][cnt] = max(skip, take);
    }
    int maxTwoEvents(vector<vector<int>> &events) {
        sort(events.begin(), events.end());
        memset(t, -1, sizeof(t));
        int cnt = 0;
        return solve(0, cnt, events);
    }
};