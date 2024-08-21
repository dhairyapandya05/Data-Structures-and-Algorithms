int ninjaTraining(int n, vector<vector<int>> &points)
{
    vector<vector<int>>dp(points.size(),vector<int>(4,0));
    vector<int>prev(4,0);
    prev[0]=max(points[0][1],points[0][2]);
    prev[1]=max(points[0][0],points[0][2]);
    prev[2]=max(points[0][1],points[0][0]);
    prev[3]=max(points[0][0],max(points[0][1],points[0][2]));

    for (int day = 1; day < n; day++) {
        vector<int>curr(4,0);
        for(int last=0;last<4;last++){
            curr[last]=0;
            for (int i = 0; i < 3; i++) {
                if (last != i) {
                    int point=points[day][i]+prev[i];
                    curr[last]=max(point,curr[last]);
                }
            }
        }
        prev=curr;

    }

    return prev[3];
}