https://www.naukri.com/code360/problems/ninja-s-training_3621003?source=youtube&campaign=striver_dp_videos&utm_source=youtube&utm_medium=affiliate&utm_campaign=striver_dp_videos&leftPanelTabValue=PROBLEM
int solve(int day, int last, vector<vector<int>> &points,vector<vector<int>> &dp) {
    if (day == 0) {
        int maxi=0;
        for (int i = 0; i < points[0].size(); i++) {
            if (last != i) {
                maxi=max(maxi,points[0][i]);
            }
        }
        return maxi;
    }
    if (dp[day][last] != -1) {
        return dp[day][last];
    }
    int maxi=0;
    for (int i = 0; i < points[day].size(); i++) {
        if (last != i) {
            int point=points[day][i]+solve(day-1, i, points,dp);
            maxi=max(point,maxi);
        }
    }
    return dp[day][last]=maxi;
}
int ninjaTraining(int n, vector<vector<int>> &points)
{
    // Write your code here.
    vector<vector<int>>dp(points.size(),vector<int>(4,-1));
    return solve(n-1,3,points,dp);
}