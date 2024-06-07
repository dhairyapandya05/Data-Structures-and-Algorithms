//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    // Function to return Breadth First Traversal of given graph.
    void solve(int u,unordered_map<int,vector<int>>& adj,vector<int>& result,vector<bool>& visited){
        queue<int> q;
        q.push(u);
        visited[u]=true;
        while(!q.empty()){
            int n=q.size();
            while(n--){
                int temp=q.front();
                result.push_back(temp);
                q.pop();
                for(auto v=adj[temp].begin();v!=adj[temp].end();v++){
                    if(visited[*v]==false){
                        q.push(*v);
                        visited[*v]=true;
                    }
                }
            }
        }
    }
    
    vector<int> bfsOfGraph(int V, vector<int> mp[]) {
        // Code here
        unordered_map<int,vector<int>> adj;
        for(int u=0;u<V;u++){
            for(auto v=mp[u].begin();v<mp[u].end();v++){
                adj[u].push_back(*v);
            }
        }
        vector<int> result;
        vector<bool> visited (V,false);
        solve(0,adj,result,visited);
        return result;
    }
};

//{ Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int V, E;
        cin >> V >>

            E;

        vector<int> adj[V];

        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
            // 		adj[v].push_back(u);
        }
        // string s1;
        // cin>>s1;
        Solution obj;
        vector<int> ans = obj.bfsOfGraph(V, adj);
        for (int i = 0; i < ans.size(); i++) {
            cout << ans[i] << " ";
        }
        cout << endl;
    }
    return 0;
}
// } Driver Code Ends