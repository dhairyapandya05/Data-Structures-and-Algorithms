#include<bits/stdc++.h>

int maxProfit(vector<int>& prices)
{
    // Write your code here.
    int n=prices.size();
    vector<vector<int>> after (2,vector<int>(3,0));
    vector<vector<int>> curr (2,vector<int>(3,0));
    for (int i = n - 1; i >= 0; i--) {
      for (int buy = 0; buy <= 1; buy++) {
          for(int limit=1;limit<=2;limit++){
              if(buy==1){
                curr[buy][limit]=max(-prices[i]+after[0][limit],after[1][limit]);
            }
            else{
                curr[buy][limit]=max(prices[i]+after[1][limit-1],after[0][limit]);
            }
            
          }
      }
      after=curr;
    }
    return after[1][2];
}