    int solve(int idx,vector<pair<int,int>>& info,int W,vector<vector<int>>&dp){
        if(idx>=info.size() or W==0){
            return 0;
        }
        if(dp[idx][W]!=-1){
            return dp[idx][W];
        }

        int skip=solve(idx+1,info,W,dp);
        int take=0;
        if(W>=info[idx].second){
            take=info[idx].first+solve(idx,info,W-info[idx].second,dp);
        }
        return dp[idx][W]=max(take,skip);
    }
    int knapSack(int N, int W, int val[], int wt[])
    {
        // code here
        auto cmp=[&](pair<int,int>&p1,pair<int,int>&p2){
            if((p1.first/p1.second)==(p2.first/p2.second)){
                return p1.first>p2.first;
            }
            return (p1.first/p1.second)>(p2.first/p2.second);
        };
        vector<pair<int,int>> info;
        for(int i=0;i<N;i++){
            info.push_back({val[i],wt[i]});
        }
        sort(info.begin(),info.end(),cmp);
        vector<vector<int>>dp(N,vector<int>(W+1,-1));
        return solve(0,info,W,dp);
    }