class Solution {
public:
    int tupleSameProduct(vector<int> &nums) {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        int tuples = 0;
        for (int i = 0; i < n; i++) {
            for (int j = n - 1; j > i; j--) {
                int product = nums[i] * nums[j];
                unordered_set<int> st;
                for (int k = i + 1; k < j; k++) {
                    if (product % nums[k] == 0) {
                        int dVALUE = product / nums[k];
                        if (st.find(dVALUE) != st.end()) {
                            tuples++;
                        }
                        st.insert(nums[k]);
                    }
                }
            }
        }
        return tuples * 8;
    }
};

// Approach 2 TC:O(n^2)
class Solution {
public:
    int tupleSameProduct(vector<int> &nums) {
        int n = nums.size();
        int tuples = 0;

        unordered_map<int, int> mp; // product -> frequency

        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                int p = nums[i] * nums[j];
                mp[p]++;
            }
        }

        for (auto &it : mp) {
            int prod = it.first;
            int freq = it.second;

            tuples += (freq * (freq - 1)) / 2;
        }

        return tuples * 8;
    }
};