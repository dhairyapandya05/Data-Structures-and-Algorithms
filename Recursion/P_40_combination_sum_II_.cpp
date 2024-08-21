class Solution {
public:
    void solve(vector<int>& sortedcandidates, vector<vector<int>>& result,
               vector<int>& curr, int idx, int target) {
        if (target < 0) {
            return;
        }
        if (target == 0) {
            result.push_back(curr);
            return;
        }
        for (int i = idx; i < sortedcandidates.size(); i++) {
            if (i > idx and sortedcandidates[i] == sortedcandidates[i-1]) {
                continue;
            }
            curr.push_back(sortedcandidates[i]);
            solve(sortedcandidates, result, curr, i + 1,
                  target - sortedcandidates[i]);
            curr.pop_back();
        }
    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(),candidates.end());
        vector<vector<int>> result;
        vector<int> curr;
        solve(candidates, result, curr, 0, target);
        return result;
    }
};