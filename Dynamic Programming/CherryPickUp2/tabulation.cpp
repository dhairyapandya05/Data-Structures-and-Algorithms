    int solve(int n, int m, vector<vector<int>>& grid) {
        // code here
        // dp[n][m][m];
        vector<vector<vector<int>>>dp(n,vector<vector<int>>(m,vector<int>(m,0)));
        for(int i=0;i<m;i++){
            for(int j=0;j<m;j++){
                if(i==j){
                    dp[n-1][i][j]=grid[n-1][j];
                }
                else{
                    dp[n-1][i][j]=grid[n-1][j]+grid[n-1][i];
                }
            }
        }
        
        for(int row=n-2;row>=0;row--){
            for(int Aj=0;Aj<m;Aj++){
                for(int Bj=0;Bj<m;Bj++){
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
                            if(Aj+i>=0 and Bj+j>=0 and Aj+i<m and Bj+j<m)
                            value+=dp[row+1][Aj+i][Bj+j];
                            else{
                                value=-1e8;
                            }
                            maxi=max(maxi,value);
                        }
                    }
                    dp[row][Aj][Bj]=maxi;
                }
            }
        }
        
        
        return dp[0][0][m-1];
    }