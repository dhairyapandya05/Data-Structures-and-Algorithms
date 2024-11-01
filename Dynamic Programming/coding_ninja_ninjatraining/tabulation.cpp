int ninjaTraining(int n, vector<vector<int>> &points)
{
    vector<vector<int>>dp(points.size(),vector<int>(4,0));
    dp[0][1]=max(points[0][0],points[0][2]);
    dp[0][0]=max(points[0][1],points[0][2]);
    dp[0][2]=max(points[0][1],points[0][0]);
    dp[0][3]=max(points[0][0],max(points[0][1],points[0][2]));

    for (int day = 1; day < n; day++) {
        for(int last=0;last<4;last++){
            dp[day][last]=0;
            for (int i = 0; i < 3; i++) {
                if (last != i) {
                    int point=points[day][i]+dp[day-1][i];
                    dp[day][last]=max(point,dp[day][last]);
                }
            }
        }
    }

    return dp[n-1][3];
}