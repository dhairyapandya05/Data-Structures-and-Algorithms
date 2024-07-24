class Solution {
public:
    int distributepages(int n,vector<int>& arr,long long mid){
        int noofstudent=1;
        int numberofpages=0;
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
    int findPages(int n, vector<int>& arr, int m) {
        // code here
        if (m > n) return -1;

        int low = *max_element(arr.begin(), arr.end());
        int high = accumulate(arr.begin(), arr.end(), 0);
        int ans;
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
    int splitArray(vector<int>& nums, int k) {
        return findPages(nums.size(),nums,k);
    }
};