class Solution {
  public:
    const int MOD=1000000007;
	    int countPartitions(int n, int d, vector<int>& arr) {
        // Code here
        int sum=accumulate(arr.begin(),arr.end(),0);
        if((sum-d)<0 or (sum-d)%2){
            return 0;
        }
        int target=(sum-d)/2;
        vector<vector<int>>dp(n,vector<int>(target+1,0));
        if(arr[0]==0) dp[0][0]=2;
        else dp[0][0]=1;
        if(arr[0]!=0 and arr[0]<=target)dp[0][arr[0]]=1;
        for (int i = 1; i < n; i++) {
            for (int summ = 0; summ <= target; summ++) {
                int nottake = dp[i-1][summ];
                int take = 0;
                if (summ - arr[i] >= 0) {
                    take = dp[i - 1][summ - arr[i]];
                }
                dp[i][summ] = (take + nottake) % MOD;
            }
        }

        return dp[n-1][target] % MOD;
        
    }
};