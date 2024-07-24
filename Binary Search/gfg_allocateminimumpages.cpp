class Solution {
  public:
    // Function to find minimum number of pages.
    
    int distributepages(int n,int arr[],long long mid){
        int noofstudent=1;
        long long numberofpages=0;
        for(int i=0;i<n;i++){
            if(numberofpages+arr[i]<=mid){
                numberofpages+=arr[i];
            }
            else{
                numberofpages=arr[i];
                noofstudent++;
            }
        }
        return noofstudent;
    }
    long long findPages(int n, int arr[], int m) {
        // code here
        if (m > n) return -1;

        int low = *max_element(arr, arr+n);
        int high = accumulate(arr, arr+n, 0);
        long long ans;
        while(low<=high){
            int mid=low+(high-low)/2;
            int noofstudents=distributepages(n,arr,mid);
            if(noofstudents>m){
                low=mid+1;
            }
            else{
                ans=mid;
                high=mid-1;
            }
        }
        return ans;
    }
};