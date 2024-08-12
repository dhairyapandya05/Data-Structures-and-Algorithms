class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        int startingcol = 0;
        int startingrow = 0;
        int endingcol = n - 1;
        int endingrow = n - 1;
        vector<vector<int>> ans(n, vector<int>(n));
        int count = 1;
        while (count <= n * n) {
            for (int i = startingcol; i <= endingcol and count <= n * n; i++) {
                ans[startingrow][i] = count;
                count++;
            }
            startingrow++;
            for (int i = startingrow; i <= endingrow and count <= n * n; i++) {
                ans[i][endingcol] = count;
                count++;
            }
            endingcol--;
            for (int i = endingcol; i >= startingcol and count <= n * n; i--) {
                ans[endingrow][i] = count;
                count++;
            }
            endingrow--;
            for (int i = endingrow; i >= startingrow and count <= n * n; i--) {
                ans[i][startingcol] = count;
                count++;
            }
            startingcol++;
        }
        return ans;
    }
};