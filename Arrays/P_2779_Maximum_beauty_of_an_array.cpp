class Solution {
public:
    int maximumBeauty(vector<int> &nums, int k) {
        vector<pair<int, int>> intervals;
        int n = nums.size();
        for (int i = 0; i < n; i++) {
            intervals.push_back({nums[i] - k, nums[i] + k});
        }

        sort(intervals.begin(), intervals.end());
        deque<pair<int, int>> de;
        int maxBeauty = 0;
        for (int i = 0; i < n; i++) {
            while (!de.empty() and de.front().second < intervals[i].first) {
                de.pop_front();
            }
            de.push_back(intervals[i]);
            maxBeauty = max(maxBeauty, (int)de.size());
        }
        return maxBeauty;
    }
};

// Approach 1.2 Just minor improvements TC=O(NlogN)
// no need to store a pair in a queue, just site the int the ending time of the interval kyoki vahi hamae chahiyae
class Solution {
public:
    int maximumBeauty(vector<int> &nums, int k) {
        vector<pair<int, int>> intervals;
        int n = nums.size();
        for (int i = 0; i < n; i++) {
            intervals.push_back({nums[i] - k, nums[i] + k});
        }

        sort(intervals.begin(), intervals.end());
        deque<int> de;
        int maxBeauty = 0;
        for (int i = 0; i < n; i++) {
            while (!de.empty() and de.front() < intervals[i].first) {
                de.pop_front();
            }
            de.push_back(intervals[i].second);
            maxBeauty = max(maxBeauty, (int)de.size());
        }
        return maxBeauty;
    }
};

// 1.3 can also be solved by replaceing the deque with a queue

// Approach 2
class Solution {
public:
    int maximumBeauty(vector<int> &nums, int k) {
        sort(nums.begin(), nums.end());
        int right = 0;
        int maxBeauty = 0;

        for (int left = 0; left < nums.size(); left++) {
            while (right < nums.size() && nums[right] - nums[left] <= 2 * k) {
                right++;
            }
            maxBeauty = max(maxBeauty, right - left);
        }
        return maxBeauty;
    }
};

// Approach 2.1 Using binary search instead of using 2 loops

class Solution {
public:
    int binarysearch(vector<int> &nums, int target) {
        int s = 0;
        int ans = 0;
        int e = nums.size() - 1;
        while (s <= e) {
            int mid = s + (e - s) / 2;
            if (nums[mid] > target) {
                e = mid - 1;
            } else {
                ans = mid;
                s = mid + 1;
            }
        }
        return ans;
    }
    int maximumBeauty(vector<int> &nums, int k) {
        sort(nums.begin(), nums.end());
        int right = 0;
        int maxBeauty = 0;

        for (int left = 0; left < nums.size(); left++) {
            int x = nums[left];
            int y = x + (2 * k);
            int right = binarysearch(nums, y);

            maxBeauty = max(maxBeauty, right - left + 1);
        }
        return maxBeauty;
    }
};
// Approach 3 Line sweep algorithm