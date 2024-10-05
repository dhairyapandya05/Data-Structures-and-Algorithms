// its correct code is 
class Solution{   
public:
    bool isSubsetSum(vector<int>arr, int sum){
        int n=arr.size();
        // vector<vector<bool>>dp(n,vector<bool>(sum+1,false));
        vector<bool>prev(sum+1,false);
        vector<bool>curr(sum+1);
        prev[0]=true;
        curr[0]=true;
        prev[arr[0]]=true;
        // return solve(n-1,arr,sum,dp);
        for(int idx=1;idx<n;idx++){
            for(int tempsum=0;tempsum<=sum;tempsum++){
                bool skip=false;
                bool take=false;
                skip=prev[tempsum];
                if(tempsum-arr[idx]>=0){
                    take=prev[tempsum-arr[idx]];
                }
                curr[tempsum]=skip or take;
            }
            prev=curr;
        }
        return prev[sum];
    }
};


// this is the my other version of code 
class Solution{   
public:
    bool isSubsetSum(vector<int>arr, int sum){
        // code here 
        int n=arr.size();
        vector<int> succ(sum+1,0);
        vector<int> curr(sum+1,0);
        succ[0]=1;
        curr[0]=1;
        for(int idx=n-1;idx>=0;idx--){
            for(int temp=sum;temp>=0;temp--){
                bool skip=false;
                bool take=false;
                skip=succ[temp];
                if(temp-arr[idx]>=0){
                    take=succ[temp-arr[idx]];
                }
                curr[temp]=skip or take;
            }
            succ=curr;
        }
        return succ[sum];
    }
};