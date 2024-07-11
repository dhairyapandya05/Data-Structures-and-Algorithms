class Solution {
public:
    void storeSolution(vector<vector<char>>& board, int n,
                       vector<vector<string>>& ans) {
        vector<string> temp;
        for (int i = 0; i < n; i++) {
            string output = "";
            for (int j = 0; j < n; j++) {
                output.push_back(board[i][j]);
            }
            temp.push_back(output);
        }
        ans.push_back(temp);
    }

    bool isSafe(int n, vector<vector<char>>& board, int col, int row) {
        // row check
        int i = row;
        int j = col;
        while (j >= 0) {
            if (board[i][j] == 'Q') {
                return false;
            }
            j--;
        }
        // check for upper left corner
        i = row;
        j = col;
        while (j >= 0 && i >= 0) {
            if (board[i][j] == 'Q') {
                return false;
            }
            j--;
            i--;
        }

        // check for lower left corner
        i = row;
        j = col;
        while (j >= 0 && i < n) {
            if (board[i][j] == 'Q') {
                return false;
            }
            j--;
            i++;
        }
        return true;
    }
    void solve(int n, vector<vector<char>>& board, int col,
               vector<vector<string>>& ans) {
        // base case
        if (col == n) {
            storeSolution(board, n, ans);
            return;
        }

        for (int i = 0; i < n; i++) {
            if (isSafe(n, board, col, i)) {
                board[i][col] = 'Q';
                solve(n, board, col + 1, ans);
                board[i][col] = '.';
            }
        }
    }
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<char>> board(n, vector<char>(n, '.'));
        vector<vector<string>> ans;
        int col = 0;
        // string rowans;
        solve(n, board, col, ans);
        return ans;
    }
};