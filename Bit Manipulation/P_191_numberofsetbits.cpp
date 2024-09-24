// Method 1
class Solution {
public:
    int hammingWeight(int n) {
        int cnt=0;
        for(int i=30;i>=0;i--){
            if((n>>i)&1==1){
                cnt++;
            }
        }
        return cnt;
    }
};

// Method 2
class Solution {
public:
    int hammingWeight(int n) {
        int cnt=0;
        while(n!=0){
            n=n&(n-1);
            cnt++;
        }
        return cnt;
    }
};
// Method 3
class Solution {
public:
    int hammingWeight(int n) {
        int cnt=0;
        while(n!=0){
            cnt+=(n%2);
            n/=2;
        }
        return cnt;
    }
};
// Method 4
