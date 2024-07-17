class Solution {
public:
int perimeter=0;
    void dfs(vector<vector<int>>& grid,int i,int j,int& rows,int& cols){

        if(i<0 or i>=rows or j<0 or j>=cols or grid[i][j]==0){
            perimeter++;
            return;
        }
        if(grid[i][j]==2){
            return;
        }
        grid[i][j]=2; //we are marking it as visited 
        dfs(grid,i-1,j,rows,cols);
        dfs(grid,i+1,j,rows,cols);
        dfs(grid,i,j-1,rows,cols);
        dfs(grid,i,j+1,rows,cols);
    }
    int islandPerimeter(vector<vector<int>>& grid) {
        int rows=grid.size();
        int cols=grid[0].size();
        for(int i=0;i<rows;i++){
            for(int j=0;j<cols;j++){
                if(grid[i][j]==1){
                    dfs(grid,i,j,rows,cols);
                }
            }
        }
        return perimeter;
    }
};