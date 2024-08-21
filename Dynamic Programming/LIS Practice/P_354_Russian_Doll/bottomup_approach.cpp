class Solution {
public:
    int maxEnvelopes(vector<vector<int>>& envelopes) {
        auto cmp=[&](vector<int>& a,vector<int>& b){
            if(a[0]==b[0]){
                return a[1]<b[1];
            }
            return a[0]<b[0];
        };
        sort(envelopes.begin(),envelopes.end(),cmp);
        int n=envelopes.size();
        vector<int>dp(n+1,1);
        int maxDoll=1;
        for(int i=0;i<n;i++){
            for(int j=0;j<i;j++){
                if(envelopes[i][0]>envelopes[j][0] and envelopes[i][1]>envelopes[j][1]){
                    dp[i]=max(dp[i],dp[j]+1);
                }
            }
            maxDoll=max(maxDoll,dp[i]);
        }
        return maxDoll;
    }
};