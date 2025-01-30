class Solution {
public:
    double findMedianSortedArrays(vector<int> &nums1, vector<int> &nums2) {
        int n1 = nums1.size();
        int n2 = nums2.size();
        int n = n1 + n2;
        int leftside = (n1 + n2 + 1) >> 1; // basically n1+n2/2 floor value;
        if (n1 > n2)
            return findMedianSortedArrays(nums2, nums1);
        int s = 0;
        int e = n1;
        while (s <= e) {
            int mid1 = s + (e - s) / 2;
            int mid2 = leftside - mid1;
            int l1 = (mid1 - 1 >= 0) ? nums1[mid1 - 1] : INT_MIN;
            int r1 = (mid1 < n1) ? nums1[mid1] : INT_MAX;
            int l2 = (mid2 - 1 >= 0) ? nums2[mid2 - 1] : INT_MIN;
            int r2 = (mid2 < n2) ? nums2[mid2] : INT_MAX;
            if (l1 <= r2 and l2 <= r1) {
                if (n % 2 == 0) {
                    return (max(l1, l2) + min(r1, r2)) / 2.0;
                } else {
                    return max(l1, l2);
                }
            }
            if (r1 < l2) {
                s = mid1 + 1;

            } else {
                e = mid1 - 1;
            }
        }
        return 0.0;
    }
};

// Approach 2
// Approach-1 - Brute Force
// T.C : O(m+n)
// S.C : O(m+n)
class Solution {
public:
    double findMedianSortedArrays(vector<int> &nums1, vector<int> &nums2) {
        int m = nums1.size();
        int n = nums2.size();

        vector<int> temp(m + n);
        int i = 0, j = 0, k = 0;

        while (i < m && j < n) {
            if (nums1[i] < nums2[j])
                temp[k++] = nums1[i++];
            else
                temp[k++] = nums2[j++];
        }

        while (i < m)
            temp[k++] = nums1[i++];
        while (j < n)
            temp[k++] = nums2[j++];

        int size = m + n;

        if (size % 2 != 0)
            return temp[size / 2];

        return (temp[size / 2] + temp[(size / 2) - 1]) / 2.0;
    }
};

// Approach-2 - Optimising Space from Approach-1
// T.C : O(m+n)
// S.C : O(1)
class Solution {
public:
    double findMedianSortedArrays(vector<int> &nums1, vector<int> &nums2) {
        int m = nums1.size();
        int n = nums2.size();
        int size = m + n;

        int idx1 = (size / 2) - 1;
        int element1 = -1;
        int idx2 = size / 2;
        int element2 = -1;

        int i = 0, j = 0, k = 0;

        while (i < m && j < n) {
            if (nums1[i] < nums2[j]) {
                if (k == idx1) {
                    element1 = nums1[i];
                }
                if (k == idx2) {
                    element2 = nums1[i];
                }
                i++;
            } else {
                if (k == idx1) {
                    element1 = nums2[j];
                }
                if (k == idx2) {
                    element2 = nums2[j];
                }
                j++;
            }
            k++;
        }

        while (i < m) {
            if (k == idx1) {
                element1 = nums1[i];
            }
            if (k == idx2) {
                element2 = nums1[i];
            }
            i++;
            k++;
        }

        while (j < n) {
            if (k == idx1) {
                element1 = nums2[j];
            }
            if (k == idx2) {
                element2 = nums2[j];
            }
            j++;
            k++;
        }

        if (size % 2 == 1)
            return element2;

        return (element1 + element2) / 2.0;
    }
};