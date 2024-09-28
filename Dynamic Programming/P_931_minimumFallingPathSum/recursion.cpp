class Solution {
public:
    int solve(int row,int col,vector<vector<int>>& matrix){
        if(row==matrix.size()){
            return 0;
        }
        int ans1=INT_MAX,ans2=INT_MAX,ans3=INT_MAX;
        if(col-1>=0){
            ans1=solve(row+1,col-1,matrix);
        }
        
        ans2=solve(row+1,col,matrix);
        if(col+1<matrix.size()){
            ans3=solve(row+1,col+1,matrix);
        }
        return matrix[row][col]+min({ans1,ans2,ans3});
    }
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int n=matrix.size();
        int row=0;
        int ans=INT_MAX;
        for(int col=0;col<n;col++){
            ans=min(ans,solve(row,col,matrix));
        }
        return ans;
    }
};