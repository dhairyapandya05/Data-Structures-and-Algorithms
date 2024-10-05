// its correct way is this 
class Solution{   
public:
    bool isSubsetSum(vector<int>arr, int sum){
        int n=arr.size();
        vector<vector<bool>>dp(n,vector<bool>(sum+1,false));
        for(int i=0;i<n;i++){
            dp[i][0]=true;//base cases are handled properly
        }
        dp[0][arr[0]]=true;//base case are handled
        // return solve(n-1,arr,sum,dp);
        for(int idx=1;idx<n;idx++){
            for(int tempsum=0;tempsum<=sum;tempsum++){
                bool skip=false;
                bool take=false;
                skip=dp[idx-1][tempsum];
                if(tempsum-arr[idx]>=0){
                    take=dp[idx-1][tempsum-arr[idx]];
                }
                dp[idx][tempsum]=skip or take;
            }
        }
        return dp[n-1][sum];
    }
};





// My approach
class Solution{   
public:
    bool isSubsetSum(vector<int>arr, int sum){
        // code here 
        int n=arr.size();
        vector<vector<int>> dp(n+1,vector<int>(sum+1,0));
        for(int i=0;i<=n;i++){
            dp[i][0]=1;//true   //handling the base case
        }
        for(int idx=n-1;idx>=0;idx--){
            for(int temp=sum;temp>=0;temp--){
                bool skip=false;
                bool take=false;
                skip=dp[idx+1][temp];
                if(temp-arr[idx]>=0){
                    take=dp[idx+1][temp-arr[idx]];
                }
                dp[idx][temp]=skip or take;
            }
        }
        return dp[0][sum];
    }
};