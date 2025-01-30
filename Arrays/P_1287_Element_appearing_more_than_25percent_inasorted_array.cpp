class Solution {
public:
    int findSpecialInteger(vector<int> &arr) {
        int size = arr.size();
        int qtr = size / 4;
        int cnt = 1;
        int p = arr[0];
        for (int i = 1; i < size; i++) {

            if (p == arr[i])
                cnt++;
            else
                cnt = 1;

            if (cnt > qtr)
                return arr[i];

            p = arr[i];
        }

        return p;
    }
};

// Approach 2
class Solution {
public:
    int findSpecialInteger(vector<int> &arr) {
        int n = arr.size();
        int k = n / 4;
        for (int i = 0; i < n; i++) {
            if (i + k < n and arr[i] == arr[i + k])
                return arr[i];
        }
        return -1;
    }
};

// Approaach 3
class Solution {
public:
    int findSpecialInteger(vector<int> &arr) {
        int n = arr.size();
        int k = n / 4;
        for (int i = 0; i < n;) {
            int j = (upper_bound(arr.begin(), arr.end(), arr[i]) - arr.begin());
            int freq = j - i;
            if (freq > k)
                return arr[i];
            else
                i = j;
        }
        return -1;
    }
};

// Approachb 4
class Solution {
public:
    int findSpecialInteger(vector<int> &arr) {
        int n = arr.size();
        int k = n / 4;
        for (int i = k; i < n; i += k) {
            int curr = arr[i];
            int lowerbound = (lower_bound(arr.begin(), arr.end(), curr) - arr.begin());
            int upperbound = (upper_bound(arr.begin(), arr.end(), curr) - arr.begin());
            int freq = upperbound - lowerbound;
            if (freq > k)
                return curr;
        }
        return -1;
    }
};