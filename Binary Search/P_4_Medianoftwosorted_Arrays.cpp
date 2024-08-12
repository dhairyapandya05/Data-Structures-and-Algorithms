class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
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