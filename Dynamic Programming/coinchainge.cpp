class Solution {
public:
    // int solve(vector<int>& coins, int amount){
    //     if(amount==0){
    //         return 0;
    //     }
    //     if(amount<0){
    //         return INT_MAX;
    //     }
    //     int mini=INT_MAX;
    //     for(int i=0;i<coins.size();i++){
    //         int ans=solve(coins,amount-coins[i]);
    //         if(ans!=INT_MAX){
    //             mini=min(mini,ans+1);
    //         }
    //     }
    //     return mini;
    // }
    //     int solveMemo(vector<int>& coins, int amount,vector<int>&dp){
    //     if(amount==0){
    //         return 0;
    //     }
    //     if(amount<0){
    //         return INT_MAX;
    //     }
    //     if(dp[amount]!=-1){
    //         return dp[amount];
    //     }
    //     int mini=INT_MAX;
    //     for(int i=0;i<coins.size();i++){
    //         int ans=solveMemo(coins,amount-coins[i],dp);
    //         if(ans!=INT_MAX){
    //             mini=min(mini,ans+1);
    //         }
    //     }
    //     dp[amount]=mini;
    //     return mini;
    // }

        int solveTab(vector<int>& coins, int amount,vector<int>&dp){
        if(amount==0){
            return 0;
        }
        for(int target=1;target<=amount;target++){
        int mini=INT_MAX;
            for(int i=0;i<coins.size();i++){
                if(target-coins[i]>=0){
                    int ans=dp[target-coins[i]];
                    if(ans!=INT_MAX){
                        mini=min(mini,ans+1);
                    }
                }

            }          
        dp[target]=mini;
        }

        return dp[amount];
    }
    int coinChange(vector<int>& coins, int amount) {
        vector<int> dp(amount+1,-1);
        dp[0]=0;
        if(amount==0){
            return 0;
        }
        // int ans=solveMemo(coins,amount,dp);
        int ans=solveTab(coins,amount,dp);
        if(ans==INT_MAX){
            return -1;
        }
        return ans;
        
    }
};