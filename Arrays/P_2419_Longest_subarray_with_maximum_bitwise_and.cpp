class Solution {
public:
    int longestSubarray(vector<int> &nums) {
        int number = 0;
        int result = 0;
        int streak = 0;
        for (auto it : nums) {
            if (it > number) {
                streak = 1;
                number = it;
                result = 0;
            } else if (it == number) {
                streak++;
            } else {
                streak = 0;
            }
            result = max(result, streak);
        }
        return result;
    }
};

// Always remember a&b<=a
// and also a&b<=b