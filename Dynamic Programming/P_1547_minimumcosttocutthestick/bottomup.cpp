class Solution {
public:
    int minCost(int n, vector<int>& cuts) {
        cuts.push_back(0);
        cuts.push_back(n);
        int c = cuts.size();
        vector<vector<int>> dp(c + 1, vector<int>(c + 1, 0));
        sort(cuts.begin(), cuts.end());
        for (int i=c-2;i>=1;i--) { // length of the segment
            for (int j = 1;j<=c-2; j++) {
                if(i>j){
                    continue;
                }
                int mini = 1e9;
                // Try every possible cut position within the segment
                for (int k = i; k <=j; k++) {
                    int steps = dp[i][k-1] + dp[k+1][j] + (cuts[j+1] - cuts[i-1]);
                    mini = min(mini, steps);
                }
                dp[i][j] = mini;
            }
        }
        return dp[1][c - 2];
    }
};