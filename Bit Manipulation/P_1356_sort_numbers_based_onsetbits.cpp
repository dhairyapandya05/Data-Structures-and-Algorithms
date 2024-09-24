class Solution {
public:
    vector<int> sortByBits(vector<int>& arr) {
        auto lamda=[&](int& a,int& b){
            int setbitA=__builtin_popcount(a);
            int setbitB=__builtin_popcount(b);
            if(setbitA==setbitB){
                return a<b;
            }
            return setbitA<setbitB;
        };
        sort(arr.begin(),arr.end(),lamda);
        return arr;
    }
};

// Method 2
class Solution {
public:
    int bitcnt(int a){
        int cnt=0;
        while(a){
            if((a&1)!=0){
                cnt++;
            }
            a=(a>>1);
        }
        return cnt;
    }
    // Method 3
    vector<int> sortByBits(vector<int>& arr) {
        auto lamda=[&](int& a,int& b){
            int setbitA=bitcnt(a);
            int setbitB=bitcnt(b);
            if(setbitA==setbitB){
                return a<b;
            }
            return setbitA<setbitB;
        };
        sort(arr.begin(),arr.end(),lamda);
        return arr;
    }
};
// Method 4
class Solution {
public:
    int hammingWeight(int n) {
        return __builtin_popcount(n);// its complexity is O(number of bits)
    }
};