//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    // Function to detect cycle in a directed graph.
    bool isCyclic(int V, vector<int> adj[]) {
        // code here
        vector<int> indegree (V,0);
        queue<int> q;
        vector<int>result;
        for(int i=0;i<V;i++){
            for(auto&v:adj[i]){
                indegree[v]++;
            }
        }
        
        for(int i=0;i<V;i++){
            if(indegree[i]==0){
                q.push(i);
            }
        }
        while(!q.empty()){
            int n=q.size();
            while(n--){
                int temp=q.front();
                result.push_back(temp);
                q.pop();
                for(auto&v:adj[temp]){
                    indegree[v]--;
                    if(indegree[v]==0){
                        q.push(v);
                    }
                }
            }
        }
        if(result.size()==V){
            return false;
        }
        else{
            return true;
        }
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
// link:https://www.geeksforgeeks.org/problems/detect-cycle-in-a-directed-graph/1