class Solution {
public:
    string fractionToDecimal(int numerator, int denominator) {
        string ans = "";
        int sign = 1;
        if ((numerator < 0 and denominator > 0) or
            (numerator > 0 and denominator < 0))
            sign = -1;
        long long n = abs(numerator);
        long long d = abs(denominator);
        long long q = n / d;
        long long r = n % d;
        if (r == 0) {
            if (sign == -1) {
                q = -1 * q;
            }
            return to_string(q);
        } else {
            ans += (to_string(q));
            ans.push_back('.');
            unordered_map<long long, long long> mp;
            while (r != 0) {
                auto it = mp.find(r);
                if (it != mp.end()) {
                    ans.insert(it->second, 1, '(');
                    ans.push_back(')');
                    if (sign == -1) {
                        ans = ans.insert(0, 1, '-');
                    }
                    return ans;
                }
                mp.insert({r, ans.length()});
                r *= 10;
                q = r / d;
                r = r % d;
                ans += (to_string(q));
            }
        }
        if (sign == -1) {
            ans = ans.insert(0, 1, '-');
        }
        return ans;
    }
};