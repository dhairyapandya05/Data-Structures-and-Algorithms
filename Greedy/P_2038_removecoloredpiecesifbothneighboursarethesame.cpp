class Solution {
public:
    bool winnerOfGame(string colors) {
        int n = colors.length();
        if (n <= 2) {
            return false;
        }
        int Acnt = 0, Bcnt = 0;
        for (int i = 1; i < n - 1; i++) {
            if (colors[i] == colors[i - 1] and colors[i] == colors[i + 1]) {
                if (colors[i] == 'A') {
                    Acnt++;
                } else {
                    Bcnt++;
                }
            }
        }
        if (Acnt <= Bcnt) {
            return false;
        }
        return true;
    }
};