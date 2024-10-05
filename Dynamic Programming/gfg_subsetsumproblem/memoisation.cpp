// correct method of solvinfg this 

class Solution{   
public:
    bool solve(int idx,vector<int>& arr, int sum,vector<vector<int>>&dp){
        if(sum==0){
            return true;
        }
        if(idx==0){
            return arr[idx]==sum;
        }
        if(dp[idx][sum]!=-1){
            return dp[idx][sum];
        }
        bool skip=false;
        bool take=false;
        skip=solve(idx-1,arr,sum,dp);
        if(sum-arr[idx]>=0){
            take=solve(idx-1,arr,sum-arr[idx],dp);
        }
        return dp[idx][sum]=skip or take;
    }
    bool isSubsetSum(vector<int>arr, int sum){
        int n=arr.size();
        vector<vector<int>>dp(n,vector<int>(sum+1,-1));
        return solve(n-1,arr,sum,dp);
    }
};












class Solution{   
public:
    bool solve(int idx,vector<int>& arr, int sum,vector<vector<int>>& dp){
        if(sum==0){
            return true;
        }
        
        if(idx==arr.size()){
            return false;
        }
        if(dp[idx][sum]!=-1){
            return dp[idx][sum];
        }
        bool skip=false;
        bool take=false;
        skip=solve(idx+1,arr,sum,dp);
        if(sum-arr[idx]>=0){
            take=solve(idx+1,arr,sum-arr[idx],dp);
        }
        return dp[idx][sum]=skip or take;
    }
    bool isSubsetSum(vector<int>arr, int sum){
        // code here 
        int n=arr.size();
        vector<vector<int>> dp(n,vector<int>(sum+1,-1));
        return solve(0,arr,sum,dp);
    }
};