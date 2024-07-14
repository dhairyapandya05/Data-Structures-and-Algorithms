class Solution {
public:
    vector<int> survivedRobotsHealths(vector<int>& positions,
                                      vector<int>& healths, string directions) {
        vector<int> actualidx;
        vector<int> positionalidx;
        stack<int> st;
        for (int i = 0; i < positions.size(); i++) {
            actualidx.push_back(i);
            positionalidx.push_back(i);
        }
        auto cmp = [&](int& idx1, int& idx2) {
            if (positions[idx1] < positions[idx2]) {
                return true;
            } else
                return false;
        };
        sort(positionalidx.begin(), positionalidx.end(), cmp);
        for (auto& it : positionalidx) {
            cout << it << "it";
        }
        for(int i=0;i<positionalidx.size();i++){
            if (st.empty() && directions[positionalidx[i]] == 'L') {
                continue;
            }
            if (directions[positionalidx[i]] == 'R') {
                st.push(positionalidx[i]); // we are just pushing the index
            } else {
                // we have encountered a l
                while (!st.empty() && healths[st.top()] < healths[positionalidx[i]]) {
                    healths[st.top()] = -1;
                    healths[positionalidx[i]]--; // degrading the health
                    st.pop();
                }
                if (!st.empty() && healths[st.top()] > healths[positionalidx[i]]) {
                    healths[st.top()]--;
                    healths[positionalidx[i]] = -1;
                } else if (!st.empty() && healths[st.top()] == healths[positionalidx[i]]) {
                    healths[st.top()] = -1;
                    healths[positionalidx[i]] = -1;
                    st.pop();
                } 
            }
        }
        vector<int> ans;
        for(auto& it:healths){
            if(it!=-1){
                ans.push_back(it);
            }
        }
        return ans;
    }
};
