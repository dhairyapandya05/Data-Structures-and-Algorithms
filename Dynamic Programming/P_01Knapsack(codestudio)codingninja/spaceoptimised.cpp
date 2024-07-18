int maxProfit(vector<int> &values, vector<int> &weights, int n, int capacity)
{
	// vector<vector<int>>dp(n,vector<int>(capacity+1,0));
  vector<int> prev(capacity+1,0);
  vector<int> curr(capacity+1,0);
    for (int weight = weights[0]; weight <= capacity; weight++) {
      prev[weight]=values[0];
    }

  // now I have to process 0 to w columns and 1 to n rows
  for(int idx=1;idx<n;idx++){
    for (int w = 0; w <= capacity; w++) {
        int include=0;
        if (w - weights[idx] >=0) {
        include=prev[w-weights[idx]]+values[idx];
        }
        int exclude=prev[w];
        curr[w]=max(include,exclude);
    }
    prev=curr;
  }
	return prev[capacity];
}