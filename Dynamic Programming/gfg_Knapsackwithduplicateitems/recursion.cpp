// User function Template for C++

class Solution{
public:
    int solve(int idx,vector<pair<int,int>>& info,int W){
        if(idx>=info.size() or W==0){
            return 0;
        }

        int skip=solve(idx+1,info,W);
        int take=0;
        if(W>=info[idx].second){
            take=info[idx].first+solve(idx,info,W-info[idx].second);
        }
        return max(take,skip);
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
        return solve(0,info,W);
    }
};