
class Solution {
public:
    vector<vector<char>> rotateTheBox(vector<vector<char>> &v) {
        int n = v.size(), m = v[0].size();
        vector<vector<char>> ans(m, vector<char>(n, '.'));
        for (int i = 0; i < n; i++) {
            int r = m - 1;
            for (int j = m - 1; j >= 0; j--) {
                if (v[i][j] == '#')
                    ans[r--][n - i - 1] = '#';
                else if (v[i][j] == '*') {
                    r = j - 1;
                    ans[j][n - i - 1] = v[i][j];
                }
            }
        }
        return ans;
    }
};