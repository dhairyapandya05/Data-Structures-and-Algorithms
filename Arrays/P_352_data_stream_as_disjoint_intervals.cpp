// Approach  1 Intutuion
class SummaryRanges {
public:
    unordered_set<int> st;
    SummaryRanges() {
        st.clear();
    }

    void addNum(int value) {
        st.insert(value);
    }

    vector<vector<int>> getIntervals() {
        vector<int> nums(st.begin(), st.end());
        sort(nums.begin(), nums.end());
        int n = st.size();
        vector<vector<int>> result;
        for (int i = 0; i < n; i++) {
            int left = nums[i];
            while (i < n - 1 and nums[i] + 1 == nums[i + 1]) {
                i++;
            }
            result.push_back({left, nums[i]});
        }
        return result;
    }
};

/**
 * Your SummaryRanges object will be instantiated and called as such:
 * SummaryRanges* obj = new SummaryRanges();
 * obj->addNum(value);
 * vector<vector<int>> param_2 = obj->getIntervals();
 */

//  Approacjh 2 Using set instead od unordered_set
class SummaryRanges {
public:
    set<int> st;
    SummaryRanges() {
        st.clear();
    }

    void addNum(int value) {
        st.insert(value); // log(n)
    }

    vector<vector<int>> getIntervals() {
        vector<int> nums(st.begin(), st.end());
        int n = st.size();
        vector<vector<int>> result;
        for (int i = 0; i < n; i++) {
            int left = nums[i];
            while (i < n - 1 and nums[i] + 1 == nums[i + 1]) {
                i++;
            }
            result.push_back({left, nums[i]});
        }
        return result;
    }
};

/**
 * Your SummaryRanges object will be instantiated and called as such:
 * SummaryRanges* obj = new SummaryRanges();
 * obj->addNum(value);
 * vector<vector<int>> param_2 = obj->getIntervals();
 */

// Approach 3
// using map
class SummaryRanges {
public:
    map<int, int> mp;
    SummaryRanges() {
        mp.clear();
    }

    void addNum(int value) {
        int left = value;
        int right = value;
        auto justbada = mp.upper_bound(value);
        if (justbada != mp.begin()) {
            auto just_peechae = justbada;
            just_peechae--;
            if (just_peechae->second >= value) {
                return;
            }
            if (just_peechae->second == value - 1) {
                left = just_peechae->first;
            }
        }
        if (justbada != mp.end() and justbada->first == value + 1) {
            right = justbada->second;
            mp.erase(justbada);
        }
        mp[left] = right;
    }

    vector<vector<int>> getIntervals() {
        vector<vector<int>> result;
        for (auto &it : mp) {
            result.push_back({it.first, it.second});
        }

        return result;
    }
};

/**
 * Your SummaryRanges object will be instantiated and called as such:
 * SummaryRanges* obj = new SummaryRanges();
 * obj->addNum(value);
 * vector<vector<int>> param_2 = obj->getIntervals();
 */