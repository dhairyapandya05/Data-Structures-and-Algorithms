// Approach 1 taking benefit of 0 to n elements

class Solution {
public:
    int maxChunksToSorted(vector<int> &arr) {
        const int n = arr.size();
        int cnt = 0, diff = 0;
        for (int i = 0; i < n; i++) {
            diff += arr[i] - i;
            cnt += (diff == 0);
        }
        return cnt;
    }
};

// Approach 2
class Solution {
public:
    int maxChunksToSorted(vector<int> &nums) {
        int n = nums.size();
        vector<int> prefix = nums;
        vector<int> suffix = nums;
        for (int i = 1; i < n; i++) {
            prefix[i] = max(prefix[i - 1], prefix[i]);
        }
        for (int i = n - 2; i >= 0; i--) {

            suffix[i] = min(suffix[i], suffix[i + 1]);
        }
        int chunks = 0;
        for (int i = 0; i < n; i++) {
            int pahaleaeKaMax = (i - 1 >= 0) ? prefix[i - 1] : -1;
            int baadKaMin = suffix[i];
            if (pahaleaeKaMax < baadKaMin) {
                chunks++;
            }
        }
        return chunks;
    }
};

// Approach 3
class Solution {
public:
    int maxChunksToSorted(vector<int> &nums) {
        int n = nums.size();
        int cumSum = 0, origSum = 0, chunks = 0;
        for (int i = 0; i < n; i++) {
            cumSum += nums[i];
            origSum += i;
            if (origSum == cumSum) {
                chunks++;
            }
        }
        return chunks;
    }
};

// Approach 4 Good observation
class Solution {
public:
    int maxChunksToSorted(vector<int> &nums) {
        int n = nums.size();
        int chunks = 0;
        int maxTillNow = -1;
        for (int i = 0; i < n; i++) {
            maxTillNow = max(maxTillNow, nums[i]);
            if (maxTillNow == i)
                chunks++;
        }
        return chunks;
    }
};