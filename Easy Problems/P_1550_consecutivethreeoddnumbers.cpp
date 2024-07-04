class Solution {
public:
    bool threeConsecutiveOdds(vector<int>& arr) {
        int n = arr.size();
        if (n < 3) {
            return false;
        }
        for (int i = 0, j = 0; j < n;) {

            if (arr[j] % 2 == 0) {
                j++;
                i = j;
            } else if (arr[j] % 2 == 1) {
                j++;
                if (j - i >= 3) {
                    return true;
                }
            }
        }
        return false;
    }
};