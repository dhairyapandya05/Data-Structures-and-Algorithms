class Solution {
  public:
  void dfs(vector<vector<int>>& grid,int i,int j,int rows,int cols,vector<pair<int,int>>& path,int origrow,int origcol,vector<vector<int>>& visited){

        if(i<0 or i>=rows or j<0 or j>=cols or grid[i][j]==0 or visited[i][j]==1)
            return;
        
        visited[i][j]=1;
        path.push_back({i-origrow,j-origcol});

        dfs(grid,i-1,j,rows,cols,path,origrow,origcol,visited);
        dfs(grid,i+1,j,rows,cols,path,origrow,origcol,visited);
        dfs(grid,i,j-1,rows,cols,path,origrow,origcol,visited);
        dfs(grid,i,j+1,rows,cols,path,origrow,origcol,visited);
    }
  
  
  
    int countDistinctIslands(vector<vector<int>>& grid) {
        int rows=grid.size();
        int cols=grid[0].size();
        vector<vector<int>> visited(rows,vector<int> (cols,0));
        set<vector<pair<int,int>>> st;
        for(int i=0;i<rows;i++){
            for(int j=0;j<cols;j++){
                if(!visited[i][j] and grid[i][j]==1){
                    vector<pair<int,int>> path;
                    dfs(grid,i,j,rows,cols,path,i,j,visited);
                    st.insert(path);
                }
            }
        }
        return st.size();
        
    }
};