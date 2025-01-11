class Solution {
public:
    bool containsNearbyDuplicate(vector<int> &nums, int k) {
        int i = 0, j = 0;
        unordered_map<int, int> mp;
        unordered_set<int> st;
        int n = nums.size();
        while (j < n) {
            st.insert(nums[j]);
            mp[j]++;
            if (j - i <= k) {
                if (st.size() < k) {
                    return true;
                }
                if (mp[i] == 1) {
                    st.erase(nums[i]);
                }
                mp[i]--;
                i++;
            }
            j++;
        }
        return false;
    }
};

// Vvvv east approach
class Solution {
public:
    bool containsNearbyDuplicate(vector<int> &nums, int k) {
        unordered_map<int, int> mp;
        int n = nums.size();
        for (int i = 0; i < n; i++) {
            int num = nums[i];
            if (mp.find(num) == mp.end()) {
            } else {
                if (i - mp[num] <= k)
                    return true;
            }
            mp[num] = i;
        }
        return false;
    }
};