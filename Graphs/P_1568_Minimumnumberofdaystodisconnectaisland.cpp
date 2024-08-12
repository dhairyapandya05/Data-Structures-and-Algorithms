class Solution {
public:
    int n,m;
    void dfs(vector<vector<int>>& grid,int i,int j,vector<vector<bool>>& visited){
        if(i<0 or j<0 or i>=n or j>=m or grid[i][j]==0 or visited[i][j]==true){
            return;
        }
        visited[i][j]=true;
        dfs(grid,i+1,j,visited);
        dfs(grid,i,j+1,visited);
        dfs(grid,i-1,j,visited);
        dfs(grid,i,j-1,visited);
    }
    int numberofIsland(vector<vector<int>>& grid){
        int islands=0;
        vector<vector<bool>>visited(n,vector<bool>(m));
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==1 and visited[i][j]==false){
                    dfs(grid,i,j,visited);
                    islands++;
                }
            }
        }


        return islands;
    }
    int minDays(vector<vector<int>>& grid) {
        n=grid.size();
        m=grid[0].size();
        int islands=numberofIsland(grid);
        if(islands>1 or islands==0){
            return 0;
        }
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==1){
                    grid[i][j]=0;
                    int islands=numberofIsland(grid);
                    if(islands>1 or islands==0){
                        return 1;
                    }
                    grid[i][j]=1;
                }
            }
        }
        return 2;
    }
};