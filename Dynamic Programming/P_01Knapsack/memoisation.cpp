int solve(vector<int> &values, vector<int> &weights, int w,int idx,vector<vector<int>>&dp) {
  if (idx == 0) {
    if (weights[0] <= w) {
		return values[0];
    } else {
		return 0;
	}
  }
  if (dp[idx][w] != -1) {
	  return dp[idx][w];
  }
  int include=0;
  if (w - weights[idx] >=0) {
	include=solve(values,weights,w-weights[idx],idx-1,dp)+values[idx];
  }
  int exclude=solve(values,weights,w,idx-1,dp);
  return dp[idx][w]=max(include,exclude);
}

int maxProfit(vector<int> &values, vector<int> &weights, int n, int w)
{
	// Write your code here
	int idx=n-1;
	vector<vector<int>>dp(n,vector<int>(w+1,-1));
	int ans=solve(values,weights,w,idx,dp);
	return ans;
}