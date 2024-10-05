class Solution {
  public:
    const int MOD=1000000007;
	int solve(int idx,vector<int>& arr,int sum,vector<vector<int>>&dp){
	   // if(idx<0){
	   //     return 1;
	   // }
	    if (idx == 0) {
            if (sum == 0 and arr[0] == 0) {
                return 2; // Two ways: pick and not pick the element
            }
            return (sum == 0 || arr[0] == sum) ? 1 : 0; 
        }
        if(dp[idx][sum]!=-1){
            return dp[idx][sum];
        }
	    int nottake=solve(idx-1,arr,sum,dp);
	    int take=0;
	    if(sum-arr[idx]>=0){
	        take=solve(idx-1,arr,sum-arr[idx],dp);
	    }
	    return dp[idx][sum]=(take+nottake)%MOD;
	}
    int countPartitions(int n, int d, vector<int>& arr) {
        // Code here
        int sum=accumulate(arr.begin(),arr.end(),0);
        if((sum-d)<0 or (sum-d)%2){
            return 0;
        }
        int target=(sum-d)/2;
        vector<vector<int>>dp(n,vector<int>(target+1,-1));
        return solve(n-1,arr,(sum-d)/2,dp)%MOD;
    }
};