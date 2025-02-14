// Approach 1 Prefix sum good

class Solution {
public:
    vector<bool> isArraySpecial(vector<int> &nums, vector<vector<int>> &queries) {
        int n = nums.size();
        int m = queries.size();
        vector<int> cumsum(n, 0);
        for (int i = 1; i < n; i++) {
            if (nums[i] % 2 == nums[i - 1] % 2) {
                cumsum[i] = cumsum[i - 1] + 1;
            } else {
                cumsum[i] = cumsum[i - 1];
            }
        }
        vector<bool> result(m, false);
        for (int i = 0; i < m; i++) {
            int start = queries[i][0];
            int end = queries[i][1];
            if (cumsum[end] - cumsum[start] == 0) {
                result[i] = true;
            }
        }
        return result;
    }
};

// Approach 2  very good approach
class Solution {
public:
    vector<bool> isArraySpecial(vector<int> &nums, vector<vector<int>> &queries) {
        int n = nums.size();
        vector<int> validRightMostIdx(n, 0);
        int m = queries.size();
        int i = 0, j = 0;
        while (i < n) {
            if (j < i) { // safety cheque
                j = i;
            }
            while (j + 1 < n and nums[j] % 2 != nums[j + 1] % 2) {
                j++;
            }
            validRightMostIdx[i] = j;
            i++;
        }
        vector<bool> result(m, false);
        for (int i = 0; i < m; i++) {
            int start = queries[i][0];
            int end = queries[i][1];
            if (end <= validRightMostIdx[start]) {
                result[i] = true;
            }
        }
        return result;
    }
};

// Approach 3
class Solution {
public:
    bool binarySearch(vector<int> &invalidIdx, vector<int> &query) { // Important: It's a veery (hum is binary search sae yae find out kar rahae hai ki koi invalid index is query ranfge mae to nahi aa raha na aagar aa raha hai to true return karaegae varna false)important binary search
        int low = query[0] + 1;
        int high = query[1];
        int s = 0, e = invalidIdx.size() - 1;
        while (s <= e) {
            int mid = (s + (e - s) / 2);
            if (invalidIdx[mid] < low)
                s = mid + 1;
            else if (invalidIdx[mid] > high)
                e = mid - 1;
            else {
                return true;
            }
        }
        return false;
    }
    vector<bool> isArraySpecial(vector<int> &nums, vector<vector<int>> &queries) {
        int n = nums.size();
        vector<int> invalidIdx;
        int m = queries.size();
        int j = 1;
        while (j < n) {
            if (nums[j] % 2 == nums[j - 1] % 2) {
                invalidIdx.push_back(j);
            }
            j++;
        }
        vector<bool> result(m, false);

        for (int i = 0; i < m; i++) {
            bool r1 = binarySearch(invalidIdx, queries[i]);
            result[i] = !r1;
        }
        return result;
    }
};
