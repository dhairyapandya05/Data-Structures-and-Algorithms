class Solution {
public:
    double myPow(double x, int n) {
        double ans=1.0;
        long long nn=n;
        if(nn<0){
            nn=-1*nn;
        }
        while(nn){
            if(nn%2){
                ans=x*ans;
                nn=nn-1;
            }
            else{
                nn=nn/2;
                x=x*x;
            }
        }
        if(n<0){
            ans=1/double(ans);
        }
        return ans;
    }
};