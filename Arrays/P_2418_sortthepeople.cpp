class Solution {
public:
    vector<string> sortPeople(vector<string>& names, vector<int>& heights) {
        vector<pair<int,string>> st;
        int n=heights.size();
        for(int i=0;i<n;i++){
            st.push_back({heights[i],names[i]});
        }
        sort(st.begin(), st.end(), [](const pair<int, string>& a, const pair<int, string>& b) {
            return a.first > b.first;
        });
        vector<string> result;
        for(int i=0;i<n;i++){
            string name=st[i].second;
            result.push_back(name);
        }
        return result;
    }
};