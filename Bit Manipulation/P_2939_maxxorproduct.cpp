class Solution {
public:
    int M = 1e9 + 7;
    typedef long long ll;
    int maximumXorProduct(long long a, long long b, int n) {
        ll xora = 0;
        ll xorb = 0;
        for (int i = 49; i >= n; i--) {
            bool ithbitofA = ((a >> i) & 1) > 0;
            bool ithbitofB = ((b >> i) & 1) > 0;
            if (ithbitofA == true) {
                xora = (xora ^ (1ll << i));
            }
            if (ithbitofB == true) {
                xorb = (xorb ^ (1ll << i));
            }
        }
        for(int i=n-1;i>=0;i--){
            bool ithbitofA = ((a >> i) & 1) > 0;
            bool ithbitofB = ((b >> i) & 1) > 0;
            if(ithbitofA==ithbitofB){
                xora=(xora^(1ll<<i));
                xorb=(xorb^(1ll<<i));
                continue;
            }
            if(xora>xorb){
                xorb=(xorb^(1ll<<i));
            }
            else{
                xora=(xora^(1ll<<i));
            }
        }
        xora%=M;
        xorb%=M;
        return (xora*xorb)%M;
    }
};