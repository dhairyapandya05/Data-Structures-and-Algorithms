class Solution {
public:
    int maxCoins(vector<int>& piles) {
        int n=piles.size();
        sort(piles.begin(),piles.end(),greater());
        int i=1;
        int mycoins=piles[i];
        int bob=n-1;
        while(i+2<bob-1){
            bob--;
            i+=2;
            mycoins+=piles[i];
            
        }
        return mycoins;
    }
};