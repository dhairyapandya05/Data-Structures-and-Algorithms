class Solution {
public:
    long long getPrice(int num, int x) {
        long long count = 0;
        while (num > 0) {
            int val = (num & 1 << (x - 1));
            if (val != 0) {
                count++;
            }
            num = num >> x;
        }
        return count;
    }
    long long findMaximumNumber(long long k, int x) {
        long long num = 1;
        long long priceSum = 0;
        while (true) {
            int price = getPrice(num, x);
            if (priceSum + price <= k) {
                priceSum += price;
            } else {
                break;
            }
            num++;
        }
        return num-1;
    }
};