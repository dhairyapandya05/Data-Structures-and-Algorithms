class Solution{

	public:
	const int MOD=1000000007;
	int solve(int idx,int arr[],int sum){
	    if(idx<0){
	        return 1;
	    }
	    if (idx == 0) {
            if (sum == 0 and arr[0] == 0) {
                return 2; // Two ways: pick and not pick the element
            }
            return (sum == 0 || arr[0] == sum) ? 1 : 0; 
        }
	    int nottake=solve(idx-1,arr,sum);
	    int take=0;
	    if(sum-arr[idx]>=0){
	        take=solve(idx-1,arr,sum-arr[idx]);
	    }
	    return (take+nottake)%MOD;
	}
	int perfectSum(int arr[], int n, int sum)
	{
        return (solve(n-1,arr,sum))%MOD;
	}
	  
};