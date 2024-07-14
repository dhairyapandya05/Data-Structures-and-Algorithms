class Solution {
public:
    int numWaterBottles(int numBottles, int numExchange) {
        int consumed = numBottles;
        int emptybottles = numBottles;
        while (emptybottles >= numExchange) {
            int extrafullbottles = (emptybottles / numExchange);
            int remain = (emptybottles % numExchange);
            consumed += extrafullbottles;
            emptybottles = remain + extrafullbottles;
        }
        return consumed;
    }
};