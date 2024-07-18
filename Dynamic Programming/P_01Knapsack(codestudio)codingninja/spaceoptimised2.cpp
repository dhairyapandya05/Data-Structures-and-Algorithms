int maxProfit(vector<int> &values, vector<int> &weights, int n, int capacity)
{
	// vector<vector<int>>dp(n,vector<int>(capacity+1,0));
  vector<int> curr(capacity+1,0);
    for (int weight = weights[0]; weight <= capacity; weight++) {
      curr[weight]=values[0];
    }

  // now I have to process 0 to w columns and 1 to n rows
  for(int idx=1;idx<n;idx++){
    for (int w = capacity; w >=0; w--) {
        int include=0;
        if (w - weights[idx] >=0) {
        include=curr[w-weights[idx]]+values[idx];
        }
        int exclude=curr[w];
        curr[w]=max(include,exclude);
    }
  }
	return curr[capacity];
}