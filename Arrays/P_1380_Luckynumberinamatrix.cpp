class Solution {
public:
    vector<int> luckyNumbers(vector<vector<int>>& matrix) {
        vector<int> minvector;
        for (int i = 0; i < matrix.size(); i++) {
            int mini = INT_MAX;
            for (int j = 0; j < matrix[0].size(); j++) {
                mini = min(mini, matrix[i][j]);
            }
            minvector.push_back(mini);
        }

        vector<int> maxvector;
        for (int col = 0; col < matrix[0].size(); col++) {

            int cMax = INT_MIN;
            for (int row = 0; row < matrix.size(); row++) {
                cMax = max(cMax, matrix[row][col]);
            }
            maxvector.push_back(cMax);
        }

        vector<int> result;
        for (int i = 0; i < matrix.size(); i++) {
            for (int j = 0; j < matrix[0].size(); j++) {
                if(matrix[i][j]==minvector[i] and matrix[i][j]==maxvector[j]){
                    result.push_back(matrix[i][j]);
                }
            }
        }
        return result;
    }
};