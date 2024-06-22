class Solution {
public:
    typedef pair<int, int> pp;
    int findMaximizedCapital(int k, int w, vector<int>& profits,
                             vector<int>& capital) {
        vector<pp> profitcap;
        for (int i = 0; i < capital.size(); i++) {
            profitcap.push_back({capital[i], profits[i]});
        }
        auto cmp = [&](pp p1, pp p2) { return p1.first < p2.first; };
        sort(profitcap.begin(), profitcap.end(), cmp);
        priority_queue<int> pq;
        int i = 0;
        while (k--) {

            while (i < profitcap.size() and profitcap[i].first <= w) {
                pq.push(profitcap[i].second);
                i++;
            }
            if (pq.empty()) {
                return w;
                break;
            }
            w += pq.top();
            pq.pop();
        }
        return w;
    }
};