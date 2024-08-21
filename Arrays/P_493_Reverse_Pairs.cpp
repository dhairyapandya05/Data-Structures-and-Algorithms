class Solution {
public:
    int cnt = 0;
    void countPairs(vector<int>& arr, int l, int mid, int r) {
        int right = mid + 1;
        for (int left = l; left <= mid; left++) {
            while (right <= r and (long long)arr[left] > 2LL * arr[right]) {
                right++;
            }
            cnt += (right - (mid + 1));
        }
    }
    void merge(vector<int>& arr, int l, int m, int r) {
        int len1 = m - l + 1;
        int len2 = r - m;

        int left[len1];
        int right[len2];
        //  copying the array into the newly formed left and right
        for (int i = 0, k = l; i < len1; i++, k++) {
            left[i] = arr[k];
        }

        for (int i = 0, k = m + 1; i < len2; i++, k++) {
            right[i] = arr[k];
        }
        // logic
        int rightptr = 0;
        int leftptr = 0;
        int mainarrayindex = l;
        while (rightptr < len2 and leftptr < len1) {
            if (left[leftptr] < right[rightptr]) {
                arr[mainarrayindex++] = left[leftptr++];
            } else {
                arr[mainarrayindex++] = right[rightptr++];
            }
        }
        while (rightptr < len2) {
            arr[mainarrayindex++] = right[rightptr++];
        }
        while (leftptr < len1) {
            arr[mainarrayindex++] = left[leftptr++];
        }
    }

    void mergeSort(vector<int>& arr, int l, int r) {
        if (l >= r) {
            return;
        }
        int mid = l + (r - l) / 2;
        mergeSort(arr, l, mid);
        mergeSort(arr, mid + 1, r);
        countPairs(arr, l, mid, r);
        merge(arr, l, mid, r);
    }
    int reversePairs(vector<int>& nums) {
        int n = nums.size();
        mergeSort(nums, 0, n - 1);
        return cnt;
    }
};