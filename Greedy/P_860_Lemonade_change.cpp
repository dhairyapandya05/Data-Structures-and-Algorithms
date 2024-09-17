class Solution {
public:
    bool lemonadeChange(vector<int>& bills) {
        int FreqFivenotes = 0;
        int FreqTennotes = 0;
        int n = bills.size();
        for (int i = 0; i < n; i++) {
            if (bills[i] == 5) {
                FreqFivenotes++;
            }
            if (bills[i] == 10) {
                if (FreqFivenotes > 0) {
                    FreqTennotes++;
                    FreqFivenotes--;
                } else {
                    return false;
                }
            } else if (bills[i] == 20) {
                if (FreqFivenotes > 0 and FreqTennotes > 0) {
                    FreqFivenotes--;
                    FreqTennotes--;
                } else if (FreqFivenotes >= 3) {
                    FreqFivenotes -= 3;
                } else {
                    return false;
                }
            }
        }
        return true;
    }
};