class Solution {
public:
    long long maxScore(vector<int>& nums1, vector<int>& nums2, int k) {
        vector<pair<int, int>> vec;
        int n = nums1.size();
        for (int i = 0; i < nums1.size(); i++) {
            vec.push_back({nums1[i], nums2[i]});
        }
        auto cmp = [&](pair<int, int>& p1, pair<int, int>& p2) {
            return p1.second > p2.second;
        };
        sort(vec.begin(), vec.end(), cmp);
        priority_queue<int, vector<int>, greater<int>> pq;
        long long int sum = 0;
        long long int result = INT_MIN;
        int minelement = vec[k - 1].second;
        for (int i = 0; i < k; i++) {
            pq.push(vec[i].first);
            sum += vec[i].first;
        }
        result = max(result, minelement * sum);
        for (int i = k; i < n; i++) {
            minelement = vec[i].second;
            sum -= pq.top();
            pq.pop();
            pq.push(vec[i].first);
            sum += vec[i].first;
            result = max(result, sum*minelement);
        }
        return result;
    }
};