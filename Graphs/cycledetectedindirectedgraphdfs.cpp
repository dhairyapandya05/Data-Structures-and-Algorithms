//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    // Function to detect cycle in a directed graph.
    bool isCycledfs(int u,vector<int> adj[],vector<bool>& visited,vector<bool>& inRecurstionStack){
        visited[u]=true;
        inRecurstionStack[u]=true;
        // for(auto v:adj[u]){
        //     if(visited[v] and isCycledfs(v,adj,visited,inRecurstionStack)){
        //         return true;
        //     }
            
        //     else if (inRecurstionStack[v]){
        //         return true;
        //     }
        // }
        // list<int>::iterator i;
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
        vector<bool> visited(V,false);
        vector<bool> inRecurstionStack(V,false);
        for(int i=0;i<V;i++){
            if(visited[i]==false and isCycledfs(i,adj,visited,inRecurstionStack)){
                return true;
            }
        }
        return false;
    }
};

//{ Driver Code Starts.

int main() {

    int t;
    cin >> t;
    while (t--) {
        int V, E;
        cin >> V >> E;

        vector<int> adj[V];

        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
        }

        Solution obj;
        cout << obj.isCyclic(V, adj) << "\n";
    }

    return 0;
}

// } Driver Code Ends