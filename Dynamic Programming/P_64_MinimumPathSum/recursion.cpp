class Solution {
public:
    int solve(int i,int j,int& n,int& m,vector<vector<int>>& grid,int& mini,int temppath){
        if(i >= n || j >= m) return INT_MAX;
        if(i==n-1 and j==m-1){
            mini=min(mini,temppath+grid[i][j]);
            return mini;
        }
        int down=solve(i+1,j,n,m,grid,mini,temppath+grid[i][j]);
        int right=solve(i,j+1,n,m,grid,mini,temppath+grid[i][j]);
        return min(down,right);
    }
    int minPathSum(vector<vector<int>>& grid) {
        int mini=INT_MAX;
        int temppath=0;
        int n=grid.size();
        int m=grid[0].size();
        int ans=solve(0,0,n,m,grid,mini,temppath);
        return mini;
    }
};