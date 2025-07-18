//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// O(E*log(V))
class Solution {
public:
    // Function to find the shortest distance of all the vertices
    // from the source vertex S.
    vector<int> dijkstra(int V, vector<vector<int>> adj[], int S) {
        // Code here
        vector<int> result(V, INT_MAX);
        ;
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> q; // minheap
        // dist,node
        q.push({0, S});
        result[S] = 0;
        while (!q.empty()) {
            int dist = q.top().first;
            int node = q.top().second;
            q.pop();

            for (auto &temp : adj[node]) {
                int adjnode = temp[0];
                int wt = temp[1];
                if (dist + wt < result[adjnode]) {
                    result[adjnode] = dist + wt;
                    q.push({dist + wt, adjnode});
                }
            }
        }
        return result;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int V, E;
        cin >> V >> E;
        vector<vector<int>> adj[V];
        int i = 0;
        while (i++ < E) {
            int u, v, w;
            cin >> u >> v >> w;
            vector<int> t1, t2;
            t1.push_back(v);
            t1.push_back(w);
            adj[u].push_back(t1);
            t2.push_back(u);
            t2.push_back(w);
            adj[v].push_back(t2);
        }
        int S;
        cin >> S;

        Solution obj;
        vector<int> res = obj.dijkstra(V, adj, S);

        for (int i = 0; i < V; i++)
            cout << res[i] << " ";
        cout << endl;
    }

    return 0;
}

// } Driver Code Ends
// link:https://www.geeksforgeeks.org/problems/implementing-dijkstra-set-1-adjacency-matrix/1
