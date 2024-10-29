class Solution {
public:
    int solve(int i,vector<int>& arr,int& n, int& k){
        if(i==n){
            return 0;
        }
        int maxi=INT_MIN; 
        int len=0;
        int maxAns=INT_MIN;
        for(int j=i;j<min(n,i+k);j++){
            len++;
            maxi=max(maxi,arr[j]);
            int sum=(len*maxi)+solve(j+1,arr,n,k);
            maxAns=max(sum,maxAns);
        }
        return maxAns;
    }
    int maxSumAfterPartitioning(vector<int>& arr, int k) {
        int n=arr.size();
        return solve(0,arr,n,k);
    }
};