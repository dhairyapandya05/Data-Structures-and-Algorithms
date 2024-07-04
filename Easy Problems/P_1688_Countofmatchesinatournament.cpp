class Solution {
public:
    int numberOfMatches(int n) {
        int totalmatches=0;
        while(n!=1){
            int matches=n/2;
            totalmatches+=matches;
            n=n-matches;
        }
        return totalmatches;
    }
};