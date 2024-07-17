class Solution {
public:
    void dfs(vector<vector<char>>& grid,int i,int j,int& rows,int& cols){

        if(i<0 or i>=rows or j<0 or j>=cols or grid[i][j]=='0' or grid[i][j]=='$'){
            return;
        }
        grid[i][j]='$'; //we are marking it as visited 
        dfs(grid,i-1,j,rows,cols);
        dfs(grid,i+1,j,rows,cols);
        dfs(grid,i,j-1,rows,cols);
        dfs(grid,i,j+1,rows,cols);
    }
    int numIslands(vector<vector<char>>& grid) {
        int rows=grid.size();
        int cols=grid[0].size();
        int count=0;
        for(int i=0;i<rows;i++){
            for(int j=0;j<cols;j++){
                if(grid[i][j]=='1'){
                    dfs(grid,i,j,rows,cols);
                    count++;
                }
            }
        }
        return count;
    }
};