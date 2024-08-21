https://www.geeksforgeeks.org/problems/geek-jump/1?utm_source=youtube&utm_medium=collab_striver_ytdescription&utm_campaign=geek-jump
class Solution {
  public:
    int solve(vector<int>& height,int n,vector<int>& dp){
        if(n<=0){
            return 0;
        }
        if(dp[n]!=-1){
            return dp[n];
        }
        int takingnextstep=solve(height,n-1,dp)+abs(height[n]-height[n-1]);
        int takenexttonextstep=INT_MAX;
        if(n>1)
        takenexttonextstep=solve(height,n-2,dp)+abs(height[n]-height[n-2]);
        return dp[n]=min(takingnextstep,takenexttonextstep);
    }
    int minimumEnergy(vector<int>& height, int n) {
        // Code here
        vector<int> dp(n,-1);
        return solve(height,n-1,dp);
    }
};