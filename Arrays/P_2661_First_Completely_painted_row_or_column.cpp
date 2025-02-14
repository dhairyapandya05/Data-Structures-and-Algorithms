class Solution {
public:
    int firstCompleteIndex(vector<int> &arr, vector<vector<int>> &mat) {
        int nr = mat.size();
        int nc = mat[0].size();
        std::unordered_map<int, pair<int, int>> coords;
        std::vector<int> visitedr(nr, 0), visitedc(nc, 0);
        for (int r = 0; r < nr; r++) {
            for (int c = 0; c < nc; c++) {
                coords[mat[r][c]] = {r, c};
            }
        }
        int e = 0;
        for (e = 0; e < arr.size(); e++) {
            auto [r, c] = coords[arr[e]];
            if (++visitedr[r] == nc || ++visitedc[c] == nr)
                return e;
        }
        return arr.size();
    }
};

// Approach 2
class Solution {
public:
    int firstCompleteIndex(vector<int> &arr, vector<vector<int>> &mat) {
        int n = mat.size();
        int m = mat[0].size();
        unordered_map<int, int> mp;
        vector<int> visitedr(n, 0), visitedc(m, 0);
        int t = arr.size();
        for (int i = 0; i < t; i++) {
            int val = arr[i];
            mp[val] = i;
        }
        int minIdx = t - 1;
        for (int r = 0; r < n; r++) {
            int lastIdx = INT_MIN;
            for (int c = 0; c < m; c++) {
                int val = mat[r][c];
                int idx = mp[val];
                lastIdx = max(lastIdx, idx);
            }
            minIdx = min(minIdx, lastIdx);
        }

        for (int c = 0; c < m; c++) {
            int lastIdx = INT_MIN;
            for (int r = 0; r < n; r++) {
                int val = mat[r][c];
                int idx = mp[val];
                lastIdx = max(lastIdx, idx);
            }
            minIdx = min(minIdx, lastIdx);
        }
        return minIdx;
    }
};