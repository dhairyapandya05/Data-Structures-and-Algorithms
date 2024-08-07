//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    // Function to detect cycle in an undirected graph.
    bool iscycleBFS(int u,vector<int> adj[],vector<bool>& visited){
        queue<pair<int, int>> q; // pair<child,parent>
        q.push({u, -1});
        visited[u] = true;

        while (!q.empty()) {
            int temp = q.front().first;
            int parent = q.front().second;
            q.pop();

            for (auto v : adj[temp]) {
                if (!visited[v]) {
                    visited[v] = true;
                    q.push({v, temp});
                } else if (v != parent) {
                    return true; // A cycle is detected
                }
            }
        }
        return false;
    }
    bool isCycle(int V, vector<int> adj[]) {
        // Code here
        vector<bool>visited(V,false);
        for(int i=0;i<V;i++){
            if(!visited[i] and iscycleBFS(i,adj,visited)){
                return true;//cycle is present
            }
        }
        return false;
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
        Solution obj;
        bool ans = obj.isCycle(V, adj);
        if (ans)
            cout << "1\n";
        else
            cout << "0\n";
    }
    return 0;
}
// } Driver Code Ends
// link:https://www.geeksforgeeks.org/problems/detect-cycle-in-an-undirected-graph/1