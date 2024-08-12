class Solution {
public:
    int mySqrt(int x) {
        int s=0;
        int e=x;
        int ans;
        while(s<=e){
            long long mid=(s+e)/2;
            if(mid*mid<x){
                ans=mid;
                s=mid+1;
            }
            if(mid*mid>x){
                e=mid-1;
            }
            if(mid*mid==x){
                ans=mid;
                return ans;
            }
        }
        return ans;
    }
};
// using binary search