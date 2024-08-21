class Solution {
public:
    int maxHeight(vector<vector<int>>& cuboids) {
        for(auto& cuboid:cuboids){
            sort(cuboid.begin(),cuboid.end());
        }
        sort(cuboids.begin(),cuboids.end());
        int n=cuboids.size();
        int maxHeight=0;
        vector<int>dp(n);
        for(int i=0;i<n;i++){
            dp[i]=cuboids[i][2];
            for(int j=0;j<i;j++){
                if(cuboids[i][0]>=cuboids[j][0] and cuboids[i][1]>=cuboids[j][1] and cuboids[i][2]>=cuboids[j][2]){
                    dp[i]=max(dp[i],cuboids[i][2]+dp[j]);
                }
            }
            maxHeight = max(maxHeight, dp[i]);
        }
        return maxHeight;
    }
};