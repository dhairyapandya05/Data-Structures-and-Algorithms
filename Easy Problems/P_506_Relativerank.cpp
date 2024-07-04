class Solution {
public:
    vector<string> findRelativeRanks(vector<int>& score) {
        int n = score.size();
        vector<int> original(score);
        sort(score.begin(), score.end(), greater<int>());
        // vector<int> rank(n);
        // int j = 0;
        // for (int i = n - 1; i >= 0; i--) {
        //     rank[j] = score[i];
        //     j++;
        // }
        vector<string> ans;
        for (int i = 0; i < score.size(); i++) {
            if (original[i] == score[0]) {
                ans.push_back("Gold Medal");
            } else if (original[i] == score[1]) {
                ans.push_back("Silver Medal");
            } else if (original[i] == score[2]) {
                ans.push_back("Bronze Medal");
            } else {
                auto idx = find(score.begin(), score.end(), original[i]);
                int dist = distance(score.begin(),idx);
                string temp = to_string(dist + 1);
                ans.push_back(temp);
            }
        }
        return ans;
    }
};