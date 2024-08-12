class Solution {
public:
    int n,m;
    bool isSafe(vector<vector<char>>& board,int row,int col,char ch){
        int boardsize=board.size();
        if(ch-'0'<1 or ch-'0'>9){
            return false;
        }
        if(row<0 or row>=n or col<0 or col>=m){
            return false;
        }
        for(int i=0;i<9;i++){
            if(board[row][i]==ch){
                return false;
            }
            if(board[i][col]==ch){
                return false;
            }
            if(board[3*(row/3)+(i/3)][3*(col/3)+(i%3)]==ch){
                return false;
            }
        }
        return true;
    }
    bool validate(vector<vector<char>>& board){
        n=board.size();
        m=board[0].size();
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(board[i][j]=='.'){
                    continue;
                }
                char ch=board[i][j];
                board[i][j]='.';
                if(isSafe(board,i,j,ch)){
                    board[i][j]=ch;
                }
                else{
                    return false;
                }
            }
        }
        return true;
    }
    bool isValidSudoku(vector<vector<char>>& board) {
        return validate(board);
    }
};