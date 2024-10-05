    int sl(int row,int Aj,int Bj,int& n,int& m,vector<vector<int>>& grid,vector<vector<vector<int>>>&dp){
        if(Aj<0 or Bj<0 or Aj>=m or Bj>=m){
            return -1e8;
        }
        if(row==n-1){
            if(Aj==Bj){
                return grid[row][Aj];
            }
            else{
                return grid[row][Aj]+grid[row][Bj];
            }
        }
        if(dp[row][Aj][Bj]!=-1){
            return dp[row][Aj][Bj];
        }
        int maxi=-1e8;
        for(int i=-1;i<=1;i++){
            for(int j=-1;j<=1;j++){
                int value=0;
                if(Aj==Bj){
                    value=grid[row][Aj];
                }
                else{
                    value=grid[row][Aj]+grid[row][Bj];
                }
                value+=sl(row+1,Aj+i,Bj+j,n,m,grid,dp);
                maxi=max(maxi,value);
            }
        }
        return dp[row][Aj][Bj]=maxi;
    }
    int solve(int n, int m, vector<vector<int>>& grid) {
        // code here
        // dp[n][m][m];
        vector<vector<vector<int>>>dp(n,vector<vector<int>>(m,vector<int>(m,-1)));
        return sl(0,0,m-1,n,m,grid,dp);
    }