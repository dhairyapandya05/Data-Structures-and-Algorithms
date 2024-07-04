class Solution {
public:
    int numSpecial(vector<vector<int>>& mat) {
        int rowcnt = mat.size();
        int colcnt = mat[0].size();
        vector<int> rowOnes(rowcnt, 0);
        vector<int> colOnes(colcnt, 0);
        for (int row = 0; row < rowcnt; row++) {
            for (int col = 0; col < colcnt; col++) {
                if (mat[row][col] == 1) {
                    rowOnes[row]++;
                    colOnes[col]++;
                }
            }
        }
        int specialcnt = 0;
        for (int row = 0; row < rowcnt; row++) {
            for (int col = 0; col < colcnt; col++) {
                if(mat[row][col]==0)
                    continue;
                if (mat[row][col]==1 and rowOnes[row] == 1 and colOnes[col] == 1) {
                    specialcnt++;
                }
            }
        }
        return specialcnt;
    }
};