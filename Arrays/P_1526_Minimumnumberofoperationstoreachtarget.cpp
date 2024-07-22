class Solution {
public:
    int minNumberOperations(vector<int>& target) {
        int curr = 0;
        int prev = 0;
        int result = 0;
        for (int i = 0; i < target.size(); i++) {
            curr = target[i];
            if (abs(curr) > abs(prev)) {
                result += abs(curr - prev);
            }
            prev = curr;
        }
        return result;
    }
};