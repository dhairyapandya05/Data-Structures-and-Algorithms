class Solution {
  public:
    // arr[]: Input Array
    // N : Size of the Array arr[]
    // Function to count inversions in the array.
    long long int inversionCount(long long arr[], int n) {
        vector<long long int> smaller(n,0);
        for(int i=0;i<n-1;i++){
            int cmp=arr[i];
            for(int j=i+1;j<n;j++){
                if(arr[j]<arr[i]){
                    smaller[i]++;
                }
            }
        }
        long long int finalans=0;
        for(auto it:smaller){
            if(it!=0){
                finalans+=it;
            }
        }
        return finalans;
    }
};