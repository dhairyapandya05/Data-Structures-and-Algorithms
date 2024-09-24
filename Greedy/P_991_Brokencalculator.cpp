class Solution {
public:
    int brokenCalc(int startValue, int target) {
        int cnt = 0;
        while (target != startValue) {
            if (target % 2 == 1 or target<startValue) {
                target++;
                cnt++;
            }
            while (target % 2 == 0 and target > startValue) {
                target /= 2;
                cnt++;
            }
        }
        return cnt;
    }
};