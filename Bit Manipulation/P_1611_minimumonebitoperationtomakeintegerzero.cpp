class Solution {
public:
    int minimumOneBitOperations(int n) {
        if (n == 0) {
            return 0;
        }
        vector<long long> F(31, 0);
        F[0] = 1;
        for (int i = 1; i <= 30; i++) {
            F[i] = 2 * F[i - 1] + 1;
        }
        int result = 0;
        int sign = 1; // we will add first;
        for (int i = 30; i >= 0; i--) {
            int ith_bit = ((1 << i) & n);
            if (ith_bit != 0) {
                result+=sign*F[i];
                sign=(-1)*sign;
            }
        }
        return result;
    }
};