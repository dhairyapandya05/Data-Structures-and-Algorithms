class Solution {
  public:
    long long solve(vector<int>& bt) {
        // code here
        sort(bt.begin(),bt.end());
        long long int t=0;
        int n=bt.size();
        long long int summationwatingtime=0;
        for(int i=0;i<n;i++){
            summationwatingtime+=t;
            t+=bt[i];
        }
        return summationwatingtime/n;
    }
};