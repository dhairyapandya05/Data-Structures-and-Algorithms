int sl(int row,int Aj,int Bj,int& n,int& m,vector<vector<int>>& grid){
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
                value+=sl(row+1,Aj+i,Bj+j,n,m,grid);
                maxi=max(maxi,value);
            }
        }
        return maxi;
    }
    int solve(int n, int m, vector<vector<int>>& grid) {
        // code here
        return sl(0,0,m-1,n,m,grid);
    }