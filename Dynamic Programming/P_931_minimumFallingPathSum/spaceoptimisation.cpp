class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();
        int row = 0;
        vector<int>succ(m,0);
        vector<int>curr(m,0);
        for (int row = n - 1; row >= 0; row--) {
            for (int col = 0; col < m; col++) {
                int ans1 = INT_MAX, ans2 = INT_MAX, ans3 = INT_MAX;
                if (col - 1 >= 0) {
                    ans1 = succ[col - 1];
                }

                ans2 = succ[col];
                if (col + 1 < matrix.size()) {
                    ans3 = succ[col + 1];
                }
                curr[col] = matrix[row][col] + min({ans1, ans2, ans3});
            }
            succ=curr;
        }
        return *min_element(succ.begin(),succ.end());
    }
};