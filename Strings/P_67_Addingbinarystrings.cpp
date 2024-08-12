class Solution {
public:
    string addBinary(string a, string b) {
        int i = 0, carry = 0;
        int aLen = a.length();
        int bLen = b.length();
        string ans = "";
        while (i < aLen or i < bLen or carry != 0) {
            int x = 0;
            if (i < aLen and a[aLen - i - 1] == '1') {
                x = 1;
            }
            int y = 0;
            if (i < bLen and b[bLen - i - 1] == '1') {
                y = 1;
            }
            ans = to_string((x + y + carry) % 2) + ans;
            carry = (x + y + carry) / 2;
            i += 1;
        }
        return ans;
    }
};