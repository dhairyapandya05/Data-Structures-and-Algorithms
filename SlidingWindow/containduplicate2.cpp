class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        int i = 0, j = 0;
        set<int> s;
        int n = nums.size();
        while (j < n) {
            if (abs(i - j) > k) {
                // we will need to shrink our window size form i
                s.erase(nums[i]);
                i++;
            }
            if (s.find(nums[j]) == s.end()) {
                s.insert(nums[j]);
            } else {
                return true;
            }

            j++;
        }
        return false;
    }
};