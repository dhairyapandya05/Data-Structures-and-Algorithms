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
        // vector<vector<int>>dp(N+1,vector<int>(W+1,0));
        vector<int>adv(W+1,0);
        vector<int>curr(W+1,0);
        
        for(int row=N-1;row>=0;row--){
            for(int col=0;col<=W;col++){
                int skip=adv[col];
                int take=0;
                if(col>=info[row].second){
                    take=info[row].first+curr[col-info[row].second];
                }
                curr[col]=max(take,skip);
            }
            adv=curr;
        }
        return adv[W];
    }