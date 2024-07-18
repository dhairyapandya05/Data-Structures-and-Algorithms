https://www.naukri.com/code360/problems/1072980?topList=striver-sde-sheet-problems&utm_source=striver&utm_medium=website&leftPanelTabValue=SUBMISSION
int solve(vector<int> &values, vector<int> &weights, int w,int idx) {
  if (idx == 0) {
    if (weights[0] <= w) {
		return values[0];
    } else {
		return 0;
	}
  }
  int include=0;
  if (w - weights[idx] >=0) {
	include=solve(values,weights,w-weights[idx],idx-1)+values[idx];
  }
  int exclude=solve(values,weights,w,idx-1);
  return max(include,exclude);
}

int maxProfit(vector<int> &values, vector<int> &weights, int n, int w)
{
	// Write your code here
	int idx=n-1;
	int ans=solve(values,weights,w,idx);
	return ans;
}