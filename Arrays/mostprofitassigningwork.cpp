class Solution {
public:
    typedef pair<int, int> pp;
    int maxProfitAssignment(vector<int>& difficulty, vector<int>& profit,
                            vector<int>& worker) {
        vector<pp> vec;
        int tasks = difficulty.size();
        int profitans = 0;
        for (int i = 0; i < difficulty.size(); i++) {
            vec.push_back({difficulty[i], profit[i]});
        }
        auto cmp = [&](pp p1, pp p2) { return p1.first > p2.first; };
        sort(vec.begin(), vec.end(), cmp);
        vector<int> indexprofit(tasks);
        stack<int> st;
        st.push(vec[tasks - 1].second);
        indexprofit[tasks - 1] = vec[tasks - 1].second;
        for (int i = tasks - 2; i >= 0; i--) {
            if (vec[i].second > st.top()) {
                st.push(vec[i].second);
                indexprofit[i] = vec[i].second;
            }
            else{
                indexprofit[i] = st.top();
            }
        }

        for (int i = 0; i < worker.size(); i++) {
            int ability = worker[i];
            for (int j = 0; j < vec.size(); j++) {
                auto temp = vec[j];
                if (temp.first <= ability) {
                    // profitans += temp.second;
                    profitans += indexprofit[j];
                    break;
                }
            }
        }
        return profitans;
    }
};