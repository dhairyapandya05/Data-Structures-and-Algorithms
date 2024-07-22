class Solution {
  public:
    // Function to detect cycle in a directed graph.
    bool isCycledfs(int u,vector<int> adj[],vector<bool>& visited,vector<bool>& inRecurstionStack){
        visited[u]=true;
        inRecurstionStack[u]=true;
        for (auto i:adj[u] ){
            if (!visited[i]){
                bool ans=isCycledfs(i,adj ,visited, inRecurstionStack);
                if(ans==true)
                    return ans;
            }
                
            else{
                if (inRecurstionStack[i])
                    return true;
            }
            
        }
        inRecurstionStack[u]=false;
        return false;
        
    }
    bool isCyclic(int V, vector<int> adj[]) {
        // code here
        vector<bool> visited(V,false);// ek time aagar is vector mae update ho gaya to ho gaya
        vector<bool> inRecurstionStack(V,false);
        for(int i=0;i<V;i++){
            if(visited[i]==false and isCycledfs(i,adj,visited,inRecurstionStack)){
                return true;
            }
        }
        return false;
    }
};
// link:https://www.geeksforgeeks.org/problems/detect-cycle-in-a-directed-graph/1