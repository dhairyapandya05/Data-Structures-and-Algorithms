// link:https://www.geeksforgeeks.org/problems/minimum-platforms-1587115620/1
class Solution{
    public:
    //Function to find the minimum number of platforms required at the
    //railway station such that no train waits.
    int findPlatform(int arr[], int dep[], int n)
    {
    	// Your code here
    	sort(arr,arr+n);
    	sort(dep,dep+n);
    	int a=0;
    	int d=0;
    	int cnt=0;
    	int maxi=0;
    	while(a<n and d<n){
    	    if(arr[a] <=dep[d]){
    	        a++;
    	        cnt++;
    	    }
    	    else{
    	        d++;
    	        cnt--;
    	    }
    	    maxi=max(maxi,cnt);
    	}
    	return maxi;
    }
};