class Solution {
public:
    string largestGoodInteger(string num) {
        char ch = 'X';
        int n = num.length();
        for (int i = 2; i < n; i++) {
            if (num[i] == num[i - 1] and num[i] == num[i - 2]) {
                if (ch == 'X') {
                    ch=num[i];
                } else {
                    if (ch < num[i]) {
                        ch =num[i];
                    }
                }
            }
        }
        string ans = "";
        return (ch == 'X') ?ans: ans.insert(0, 3, ch);
    }
};