class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& mat) {
        class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& mat) {
        int n = mat.size();
        int m = mat[0].size();
        map<int, vector<int>> map;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                map[i + j].push_back(mat[i][j]);
            }
        }
        bool even = true;
        vector<int> ans;
        for (auto& it:map) {
            if (even) {
                reverse(it.second.begin(), it.second.end());
                even = false;
                ans.insert(ans.end(), it.second.begin(), it.second.end());
                continue;
            } else {
                even = true;
                ans.insert(ans.end(), it.second.begin(),it.second.end());
                continue;
            }
        }
        return ans;
    }
};
    }
};