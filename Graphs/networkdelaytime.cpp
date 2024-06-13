https://leetcode.com/problems/network-delay-time/submissions/1287528594/
class Solution {
public:
    typedef pair<int,int> pp;
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        unordered_map<int,vector<pp>> adj;
        for(auto& time:times){
            int u=time[0];
            int v=time[1];
            int w=time[2];
            adj[u].push_back({v,w});
        }

        set<pair<int,int>> pq;
        vector<int> result(n+1,INT_MAX);
        result[k]=0;
        pq.insert({k,0});
        while(!pq.empty()){
            auto temp = *pq.begin();
            pq.erase(temp);
            int v=temp.first;
            int w=temp.second;
            for(auto entry:adj[v]){
                int dest=entry.first;
                int wt=entry.second;
                if(result[dest]>wt+w){
                    if(result[dest]!=INT_MAX){
                        pq.erase({dest,result[dest]});
                    }
                    result[dest]=wt+w;
                    pq.insert({dest,result[dest]});
                }
            }
        }
        result[0]=INT_MIN;
        int ans=*max_element(result.begin(),result.end());
        return (ans==INT_MAX)?-1:ans;
    }
};