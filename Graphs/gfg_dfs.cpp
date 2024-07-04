//{ Driver Code Starts
// link:https://www.geeksforgeeks.org/problems/depth-first-traversal-for-a-graph/1
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    // Function to return a list containing the DFS traversal of the graph.
    void solve(unordered_map<int,vector<int>>& adj,int u,vector<bool>& visited,vector<int>& result){
        if(visited[u]==true){
            return;
        }
        visited[u]=true;
        result.push_back(u);
        for(auto v: adj[u]){
            if(visited[v]==false){
                solve(adj,v,visited,result);
            }
        }
    }
    // You are given a connected undirected graph. Perform a Depth First Traversal of the graph.
// Note: Use the recursive approach to find the DFS traversal of the graph starting from the 0th vertex from left to right according to the graph.
// V = 5 , adj = [[2,3,1] , [0], [0,4], [0], [2]]
    vector<int> dfsOfGraph(int V, vector<int> mp[]) {
        // Code here
        unordered_map<int,vector<int>> adj;
        for(int u=0;u<V;u++){
            adj.insert({u,mp[u]});
        }
        vector<int> result;
        vector<bool> visited(V,false);
        solve(adj,0,visited,result);
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