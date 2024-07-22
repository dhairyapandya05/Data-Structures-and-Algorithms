class Solution {
public:
    vector<pair<int, int>> directions = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
    bool find(int i, int j, int idx, vector<vector<char>>& board, string word,
              int rows, int cols) {
        if (idx >= word.length()) {
            return true;
        }
        if (i < 0 or i >= rows or j < 0 or j >= cols or
            board[i][j] != word[idx] or board[i][j] == '$') {
            return false;
        }
        char temp = board[i][j];
        board[i][j] = '$';
        for (auto it : directions) {
            if (find(i + it.first, j + it.second, idx + 1, board, word, rows,
                     cols)) {
                return true;
            }
        }
        board[i][j] = temp;
        return false;
    }
    bool exist(vector<vector<char>>& board, string word) {
        int rows = board.size();
        int cols = board[0].size();
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                if (board[i][j] == word[0] and
                    find(i, j, 0, board, word, rows, cols)) {
                    return true;
                }
            }
        }
        return false;
    }
};