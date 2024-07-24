class Solution
{
  public:
long long distributeBoards(int n, int arr[], long long mid) {
        long long noOfPainters = 1;
        long long totalLength = 0;

        for (int i = 0; i < n; i++) {
            if (totalLength + arr[i] <= mid) {
                totalLength += arr[i];
            } else {
                totalLength = arr[i];
                noOfPainters++;
            }
        }

        return noOfPainters;
    }

    long long minTime(int arr[], int n, int k) {
        long long low = *max_element(arr, arr + n);
        long long high = accumulate(arr, arr + n, 0LL);
        long long ans = high;

        while (low <= high) {
            long long mid = low + (high - low) / 2;
            int noOfPainters = distributeBoards(n, arr, mid);

            if (noOfPainters > k) {
                low = mid + 1;
            } else {
                ans = mid;
                high = mid - 1;
            }
        }

        return ans;
    }
};