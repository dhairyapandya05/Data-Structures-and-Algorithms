class Solution {
public:
    int longestSquareStreak(vector<int> &nums) {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        int maxStreak = 0;
        unordered_map<int, int> mp;
        for (int i = 0; i < n; i++) {
            int root = (int)sqrt(nums[i]);
            if (root * root == nums[i] and mp.find(root) != mp.end()) {
                mp[nums[i]] = mp[root] + 1;
            } else {
                mp[nums[i]] = 1;
            }
            maxStreak = max(maxStreak, mp[nums[i]]);
        }
        return (maxStreak >= 2) ? maxStreak : (-1);
    }
};

// Approach 2   O(n)
class Solution {
public:
    int longestSquareStreak(vector<int> &nums) {
        set<int> st(nums.begin(), nums.end());
        unordered_map<int, int> mp;
        int maxans = 0;
        int n = nums.size();
        vector<int> visited(n, 0); // unvisited
        int i = 0;
        for (auto it : st) {
            if (visited[i] == 1) {
                continue;
            }
            cout << "Value of i: " << i << endl;

            visited[i] = 1;
            long long curr = it;
            curr *= it;
            int cnt = 1;
            if (curr > 1e5) {
                break;
            }
            while (st.count(curr) != 0) {
                cnt++;
                auto itr = st.find(curr);
                int dist = distance(st.begin(), itr);
                visited[dist] = 1;
                if (curr * curr > 1e5) {
                    break;
                }
                curr *= curr;
                cout << "Value of changed curr: " << curr << endl;
            }
            mp[it] = cnt;
            cout << "it: " << it << " and " << "cnt: " << cnt << endl;
            maxans = max(maxans, cnt);
            i++;
        }
        return (maxans >= 2) ? maxans : -1;
    }
};

// Can also be solved with the help of binary search after sorting the array