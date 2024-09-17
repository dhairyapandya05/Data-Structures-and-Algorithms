#include<bits/stdc++.h>

int maxProfit(vector<int>& prices)
{
    // Write your code here.
    int n=prices.size();
    vector<vector<vector<int>>>dp(n+1,vector<vector<int>>(2,vector<int>(3,0)));
    for (int i = n - 1; i >= 0; i--) {
      for (int buy = 0; buy <= 1; buy++) {
          for(int limit=1;limit<=2;limit++){
              if(buy==1){
                dp[i][buy][limit]=max(-prices[i]+dp[i+1][0][limit],dp[i+1][1][limit]);
            }
            else{
                dp[i][buy][limit]=max(prices[i]+dp[i+1][1][limit-1],dp[i+1][0][limit]);
            }
            
          }
      }
    }
    return dp[0][1][2];
}