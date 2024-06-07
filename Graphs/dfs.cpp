//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    // Function to return a list containing the DFS traversal of the graph.
    
    void solve(unordered_map<int,vector<int>>& adj,int u,vector<int>& result,vector<bool>& visited){
        if(visited[u]==true){
            return;
        }
        visited[u]=true;
        result.push_back(u);
        for (int v : adj[u]){
            if(visited[v]==false){
                solve(adj,v,result,visited);
            }
        }
    }
    vector<int> dfsOfGraph(int V, vector<int> mp[]) {
        // Code here
        // make adjacency list
        unordered_map<int,vector<int>> adj;
        for(int i=0;i<V;i++){
            for(auto j=mp[i].begin();j!=mp[i].end();j++){
                adj[i].push_back(*j);
            }
            
        }
        
        vector<int> result;
        vector<bool> visited(V,false);
        solve(adj,0,result,visited);
        return result;
    }
};

//{ Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int V, E;
        cin >> V >> E;

        vector<int> adj[V];

        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        // string s1;
        // cin>>s1;
        Solution obj;
        vector<int> ans = obj.dfsOfGraph(V, adj);
        for (int i = 0; i < ans.size(); i++) {
            cout << ans[i] << " ";
        }
        cout << endl;
    }
    return 0;
}
// } Driver Code Ends