class Solution {
public:
    void solve_bfs(int u,vector<bool>& visited,unordered_map<int,vector<int>>& adj){
        queue<int>q;
        q.push(u);
        while(!q.empty()){
            int n=q.size();
            while(n--){
                int temp=q.front();
                visited[temp]=true;
                q.pop();
                for(auto& v:adj[temp]){
                    if(visited[v]==false){
                        q.push(v);
                    }
                }
            }
        }
    }
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n=isConnected.size();
        vector<bool> visited (n,false);
        unordered_map<int,vector<int>> adj;
        for(int u=0;u<n;u++){
            for(int v=0;v<n;v++){
                if(u!=v and isConnected[u][v]==1){
                    adj[u+1].push_back(v+1);
                }
            }
        }
int count=0;
        for(int i=1;i<=n;i++){
            if(visited[i]==false){
                solve_bfs(i,visited,adj);
                count++;
            }
        }
        return count;
    }
};
// link:https://leetcode.com/problems/number-of-provinces/