class Solution {
public:
    int divide(int dividend, int divisor) {
        bool sign = true;
        if ((dividend < 0 and divisor > 0) or (dividend > 0 and divisor < 0))
            sign = false;
        if (dividend == divisor)
            return 1;
        long n = abs(dividend);
        long d = abs(divisor);
        int result = 0;
        while (n >= d) {
            int cnt = 0;
            while (n >= d << (cnt + 1))
                cnt++;
            result += 1 << cnt;
            n -= d << cnt;
        }
        if (result == 1 << 31 and sign == true) {
            return INT_MAX;
        }
        if (result == 1 << 31 and sign == false) {
            return INT_MIN;
        }
        return (sign) ? result : -1 * result;
    }
};