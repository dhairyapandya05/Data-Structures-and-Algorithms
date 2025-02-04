class Solution {
public:
    vector<vector<int>> restoreMatrix(vector<int> &rowSum,
                                      vector<int> &colSum) {
        int n = rowSum.size();
        int m = colSum.size();
        vector<vector<int>> matrix(n, vector<int>(m, 0));
        int i = 0, j = 0;
        while (i < n and j < m) {
            int mini = min(rowSum[i], colSum[j]);
            rowSum[i] -= mini;
            colSum[j] -= mini;
            if (rowSum[i] == 0) {
                matrix[i][j] = mini;
                i++;
            } else if (colSum[j] == 0) {
                matrix[i][j] = mini;
                j++;
            }
        }
        return matrix;
    }
};