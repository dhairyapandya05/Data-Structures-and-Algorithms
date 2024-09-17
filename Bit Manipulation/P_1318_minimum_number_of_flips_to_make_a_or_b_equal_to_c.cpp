class Solution {
public:
    int minFlips(int a, int b, int c) {
        int flips=0;
        while(a!=0 or b!=0 or c!=0){
            if((c&1)==1){
                if((a&1)==0 and (b&1)==0){
                    flips++;
                }
            }
            else{
                if((a&1)==1){
                    flips++;
                }
                if((b&1)==1){
                    flips++;
                }
            }
            a=a>>1;
            b=b>>1;
            c=c>>1;
        }
        return flips;
    }
};
/*VVV important note
Specifically, c&1==1 and similar conditions do not behave as expected because of operator precedence.


*/