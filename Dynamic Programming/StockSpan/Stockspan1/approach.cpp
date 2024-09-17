#include <bits/stdc++.h> 
int maximumProfit(vector<int> &prices){
    // Write your code here.
    int n=prices.size();
    int profit=0;
    int mini=prices[0];
    for (int i = 1; i < n; i++) {
        profit=max(prices[i]-mini,profit);
        mini=min(mini,prices[i]);
    }
    return profit;
}