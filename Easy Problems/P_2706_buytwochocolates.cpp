class Solution {
public:
    int buyChoco(vector<int>& prices, int money) {
        sort(prices.begin(),prices.end());
        int leftovermoney=money-(prices[0]+prices[1]);
        return (leftovermoney>=0)? leftovermoney:money;
    }
};