class Solution {
public:
    int kthElement(int k, vector<int> &arr1, vector<int> &arr2) {
        int i = 0, j = 0;
        while (i < arr1.size() and j < arr2.size()) {
            if (arr1[i] < arr2[j]) {
                k--;
                if (k == 0) {
                    return arr1[i];
                }
                i++;
            } else if (arr1[i] >= arr2[j]) {
                k--;
                if (k == 0) {
                    return arr2[j];
                }
                j++;
            }
            // if(k==0){
            //     return (arr1[i]<arr2[j])?arr1[i]:arr2[j];
            // }
        }
        while (i < arr1.size()) {
            k--;
            if (k == 0) {
                return arr1[i];
            }
            i++;
        }
        while (j < arr2.size()) {
            k--;
            if (k == 0) {
                return arr2[j];
            }
            j++;
        }
    }
};

// Method 2 Binary Search
int kthElement(vector<int> &a, vector<int> &b, int m, int n, int k) {
    if (m > n)
        return kthElement(b, a, n, m, k);

    int left = k; // length of left half

    // apply binary search:
    int low = max(0, k - n), high = min(k, m);
    while (low <= high) {
        int mid1 = (low + high) >> 1;
        int mid2 = left - mid1;
        // calculate l1, l2, r1 and r2;
        int l1 = INT_MIN, l2 = INT_MIN;
        int r1 = INT_MAX, r2 = INT_MAX;
        if (mid1 < m)
            r1 = a[mid1];
        if (mid2 < n)
            r2 = b[mid2];
        if (mid1 - 1 >= 0)
            l1 = a[mid1 - 1];
        if (mid2 - 1 >= 0)
            l2 = b[mid2 - 1];

        if (l1 <= r2 && l2 <= r1) {
            return max(l1, l2);
        }

        // eliminate the halves:
        else if (l1 > r2)
            high = mid1 - 1;
        else
            low = mid1 + 1;
    }
    return 0; // dummy statement
}