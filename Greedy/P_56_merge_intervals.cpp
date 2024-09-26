class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        auto cmp = [&](vector<int>& v1, vector<int>& v2) {
            if (v1[0] == v2[0]) {
                return v1[1] < v2[1];
            }
            return v1[0] < v2[0];
        };
        sort(intervals.begin(), intervals.end(), cmp);
        int n = intervals.size();
        vector<vector<int>> ans;
        ans.push_back(intervals[0]);
        for (int i = 1; i < n; i++) {
            // if(ans.empty() or )
            if (i < n and intervals[i][0] <= ans.back()[1]) {
                int maxi = max(intervals[i][1], ans.back()[1]);
                ans.back()[1] = maxi;
            } else {
                ans.push_back(intervals[i]);
            }
        }
        return ans;
    }
};