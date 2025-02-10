class Solution {
public:
    long long maxMatrixSum(vector<vector<int>> &matrix) {
        long long sum = 0;
        int negative_count = 0;
        int minimum = INT_MAX;
        int n = matrix.size();
        int m = matrix[0].size();
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                int num = matrix[i][j];
                if (num < 0) {
                    ++negative_count;
                    num *= -1;
                }
                sum += num;
                minimum = min({minimum, num});
            }
        }
        if (negative_count % 2 == 1) {
            sum = sum - (minimum + minimum);
        }
        return sum;
    }
};