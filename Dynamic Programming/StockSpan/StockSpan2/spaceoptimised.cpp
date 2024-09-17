#include<bits/stdc++.h>
long getMaximumProfit(long *values, int n)
{
    //Write your code here
    vector<long> ahead {0,0};
    vector<long> curr(2);
    for (int i = n-1; i >=0; i--) {
        for(int buy=0;buy<=1;buy++){
            long profit=0;
            if(buy){
                profit=max(-values[i] +ahead[0],ahead[1]);
            } 
            else {
                profit=max(values[i]+ahead[1],ahead[0]);
            }
            curr[buy]=profit;
        }
        ahead=curr;
    }
    return ahead[1];
}