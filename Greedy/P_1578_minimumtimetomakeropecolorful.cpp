class Solution {
public:
    int minCost(string colors, vector<int>& neededTime) {
        int maxPrev = 0;
        int cnt = 0;
        int n = colors.length();
        for (int i = 0; i < n; i++) {
            int curr = neededTime[i];
            if (i > 0 and colors[i] != colors[i - 1]) {
                maxPrev = 0;
            }
            cnt += min(maxPrev, curr);
            maxPrev = max(maxPrev, curr);
        }
        return cnt;
    }
};