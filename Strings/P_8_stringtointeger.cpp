class Solution {
public:
    int myAtoi(string s) {
        long result = 0;
        int sign = 1;
        long max = INT_MAX;
        int min = INT_MIN;
        int i = 0;
        for (i = 0; i < s.length(); i++) {
            if (s[i] != ' ') {
                break;
            }
        }
        s = s.substr(i);
        int startingidx = 0;
        if (s[0] == '-') {
            sign = -1;
            startingidx = 1;
        }
        if (s[0] == '+') {
            sign = +1;
            startingidx = 1;
        }
        for (int i = startingidx; i < s.length(); i++) {
            if (!isdigit(s[i])) {
                break;
            } else if (isdigit(s[i])) {
                result = (result * 10) + int(s[i] - '0');
                if (sign == -1 and sign * result < INT_MIN) {
                    return min;
                }
                if (sign==1 and result > INT_MAX) {
                    return max * sign;
                }
            }
        }
        return result * sign;
    }
};