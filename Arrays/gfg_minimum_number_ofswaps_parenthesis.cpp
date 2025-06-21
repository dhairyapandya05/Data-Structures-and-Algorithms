class Solution {
public:
    int minimumNumberOfSwaps(string &s) {
        // code here
        int opening = 0;
        int closing = 0;
        int ucb = 0;
        int swaps = 0;
        for (auto it : s) {
            if (it == '[') {
                opening++;
                if (ucb > 0) {
                    swaps += ucb;
                    ucb--;
                }
            } else {
                closing++;
                ucb = closing - opening;
            }
        }
        return swaps;
    }
};