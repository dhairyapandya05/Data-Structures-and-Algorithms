class Solution {
  public:
    // Function to detect cycle in an undirected graph.
    bool isCycle_dfs(vector<int> adj[],int u,vector<bool>& visited,int parent){
        visited[u]=true;
        for(auto v:adj[u]){
            if(parent==v){
                continue;
            }
            if(visited[v]==true){
                return true;
            }
            if(isCycle_dfs(adj,v,visited,u)){
                return true;
            }
        }
        return false;
    }
    bool isCycle(int V, vector<int> adj[]) {
        // Code here
        vector<bool> visited(V,false);
        for(int i=0;i<V;i++){
            if(visited[i]==false and isCycle_dfs(adj,i,visited,-1)){
                return true;
            }
        }
        return false;
    }
};