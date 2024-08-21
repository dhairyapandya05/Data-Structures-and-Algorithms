class Solution {
public:
    int maxEnvelopes(vector<vector<int>>& envelopes) {
        auto cmp = [&](vector<int>& vec1, vector<int>& vec2) {
            if (vec1[0] == vec2[0]) {
                return vec1[1] > vec2[1];
            }
            return vec1[0] < vec2[0];
        };
        sort(envelopes.begin(), envelopes.end(), cmp);
        vector<int> ans;
        int n=envelopes.size();
        for(int i=0;i<n;i++){
            auto it=lower_bound(ans.begin(),ans.end(),envelopes[i][1]);
            if(it==ans.end()){
                ans.push_back(envelopes[i][1]);
            }
            else{
                *it=envelopes[i][1];
            }
        }
        return ans.size();
    }
};