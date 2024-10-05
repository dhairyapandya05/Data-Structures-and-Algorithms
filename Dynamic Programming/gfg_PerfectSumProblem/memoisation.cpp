class Solution{

	public:
	const int MOD=1000000007;
	int solve(int idx,int arr[],int sum,vector<vector<int>>& dp){
	    if(idx<0){
	        return 0;
	    }
	    if (idx == 0) {
            if (sum == 0 and arr[0] == 0) {
                return 2; // Two ways: pick and not pick the element
            }
            return (sum == 0 || arr[0] == sum) ? 1 : 0; //skip and take respectively
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
	int perfectSum(int arr[], int n, int sum)
	{
	    vector<vector<int>>dp(n,vector<int>(sum+1,-1));
        return (solve(n-1,arr,sum,dp))%MOD;
	}
	  
};