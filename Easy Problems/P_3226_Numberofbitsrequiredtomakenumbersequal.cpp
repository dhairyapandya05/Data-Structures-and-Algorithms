class Solution {
public:
    int minChanges(int n, int k) {
        int cnt = 0;
        while (n > 0 or k > 0) {
            if (n & 1 and k & 1) {
                n >>= 1;
                k >>= 1;
                continue;
            } else if (!(n & 1) and !(k & 1)) {
                n >>= 1;
                k >>= 1;
                continue;
            } else if (n & 1 and !(k & 1)) {
                cnt++;
            } else {
                return -1;
            }
            n >>= 1;
            k >>= 1;
        }
        return cnt;
    }
};