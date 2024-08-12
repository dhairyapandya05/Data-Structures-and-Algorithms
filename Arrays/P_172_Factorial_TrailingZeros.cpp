class Solution {
public:
    int trailingZeroes(int n) {
        int i=5;
        int count=0;
        while(ceil(n/i)>=1){
            count+=(n/i);
            i=i*5;
        }
        return count;
    }
};