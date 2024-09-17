class Solution {
  public:
    int getMinDiff(vector<int> &arr, int k) {
        sort(arr.begin(),arr.end());
        int n=arr.size();
        int ans=arr[n-1]-arr[0];
        int largest=arr[n-1]-k;
        int smallest=arr[0]+k;
        int mi=0,ma=0;
        for(int i=0;i<n-1;i++){
            mi=min(smallest,arr[i+1]-k);
            ma=max(largest,arr[i]+k);
            if(mi<0){
                continue;
            }
            ans=min(ans,ma-mi);
        }
        return ans;
    }
};