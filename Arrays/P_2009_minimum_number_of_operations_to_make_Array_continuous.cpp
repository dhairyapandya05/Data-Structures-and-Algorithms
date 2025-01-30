class Solution {
public:
    int minOperations(vector<int> &nums) {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        int result = INT_MAX;
        for (int i = 0; i < n; i++) {
            set<int> st; // to handle duplicate elements

            int L = nums[i];
            int R = L + n - 1;
            unordered_map<int, int> mp;
            int operation = 0;
            for (int j = 0; j < n; j++) {
                if (nums[j] >= L and nums[j] <= R and
                    st.find(nums[j]) == st.end()) {
                    st.insert(nums[j]);
                } else {
                    operation++;
                }
            }
            result = min(result, operation);
        }
        return result;
    }
};

// This is a bit tricky and can lead to TLE
// This can lead to TLE and can be eliminated easily
// This works perfectly
class Solution {
public:
    int minOperations(vector<int> &nums) {
        set<int> st(nums.begin(), nums.end());
        vector<int> temp(st.begin(), st.end());

        int n = temp.size();
        int result = INT_MAX;
        for (int i = 0; i < n; i++) {
            int L = temp[i];
            int R = L + nums.size() - 1;
            auto itrJ = upper_bound(temp.begin(), temp.end(), R);
            int j = itrJ - temp.begin();
            int inrange = j - i;
            int operation = nums.size() - inrange;
            result = min(result, operation);
        }
        return result;
    }
};