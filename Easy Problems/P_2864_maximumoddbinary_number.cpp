class Solution {
public:
    int oneBit(string s) {
        int count = 0;
        for (auto& it : s) {
            if (it == '1') {
                count++;
            }
        }
        return count;
    }
    string maximumOddBinaryNumber(string t) {
        int n = t.length();
        int ones = oneBit(t);
        int zeros = n - ones;
        string s;
        if (ones > 0) {
            s.push_back('1');
            ones--;
        }
        while (zeros) {
            s = '0' + s;
            zeros--;
        }
        while (ones) {
            s = '1' + s;
            ones--;
        }
        return s;
    }
};