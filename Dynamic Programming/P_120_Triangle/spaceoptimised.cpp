class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        int n = triangle.size();
        vector<vector<int>> dp(n, vector<int>(n, 0));
        vector<int>prev(n);
        vector<int>curr(n);
        for (int i = 0; i < n; i++) {
            prev[i] = triangle[n - 1][i]; // handling the base case
        }
        for (int level = n - 2; level >= 0; level--) {
            for (int i = 0; i <=level; i++) {
                curr[i] = triangle[level][i] + min(prev[i], prev[i + 1]);
            }
            prev=curr;
        }
        return prev[0];
    }
};