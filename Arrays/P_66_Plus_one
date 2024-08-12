class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int n = digits.size() - 1;
        int carry=0;
        for (; n >= 0; n--) {
            int ans=digits[n]+1;
            if (ans < 10) {
                digits[n] = ans;
                return digits;
            }
            digits[n] = ans % 10;
            carry = ans / 10;
        }

        if (carry == 1) {
            digits.insert(digits.begin(), carry);
        }
        return digits;
    }
};