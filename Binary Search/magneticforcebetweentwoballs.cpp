class Solution {
public:
    int numberofballspossible(vector<int>& position, int mindist) {
        // int ballcnt = 1;
        // int i = position[0];
        // while (true) {
        //     auto lb =
        //         lower_bound(position.begin(), position.end(), i + mindist);
        //     if (lb == position.end()) {
        //         return ballcnt;
        //     } else {
        //         ballcnt++;
        //         i = *lb;
        //     }
        // }
        // return -1;
        int ballcnt = 1;
        int lastball_pos = position[0];
        for (int i = 1; i < position.size(); i++) {
            if (position[i] - lastball_pos >= mindist) {
                ballcnt++;
                lastball_pos = position[i];
            }
        }
        return ballcnt;
    }
    int maxDistance(vector<int>& position, int m) {
        sort(position.begin(), position.end());
        int start = 1;
        int end = position.back() - position.front();
        int mid;
        int ans = -1;
        while (start <= end) {
            mid = start + (end - start) / 2;
            if (numberofballspossible(position, mid) >= m) {
                ans = mid;
                start = mid + 1;
            } else {
                end = mid - 1;
            }
        }
        return ans;
    }
};
// link:https://leetcode.com/problems/magnetic-force-between-two-balls/submissions/1294236725/?envType=daily-question&envId=2024-06-20