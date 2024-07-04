//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
public:
    // Function to return Breadth First Traversal of given graph.
    void solve(int u, vector<bool> &visited, vector<int> &result, unordered_map<int, vector<int>> &adj)
    {
        queue<int> q;
        q.push(u);
        visited[u] = true;
        while (!q.empty())
        {
            int n = q.size();
            while (n--)
            {
                int temp = q.front();
                q.pop();
                result.push_back(temp);
                for (auto v = adj[temp].begin(); v != adj[temp].end(); v++)
                {
                    if (visited[*v] == false)
                    {
                        q.push(*v);
                        visited[*v] = true;
                    }
                }
            }
        }
    }
    // Given a directed graph. The task is to do Breadth First Traversal of this graph starting from 0.
// Note: One can move from node u to node v only if there's an edge from u to v. Find the BFS traversal of the graph starting from the 0th vertex, from left to right according to the input graph. Also, you should only take nodes directly or indirectly connected from Node 0 in consideration.
//     V = 5, E = 4
// adj = {{1,2,3},{},{4},{},{}}
    vector<int> bfsOfGraph(int V, vector<int> mp[])
    {
        // Code here
        unordered_map<int, vector<int>> adj;
        for (int u = 0; u < V; u++)
        {
            adj[u] = mp[u];
        }
        vector<int> result;
        vector<bool> visited(V, false);
        solve(0, visited, result, adj);
        return result;
    }
};

//{ Driver Code Starts.
int main()
{
    int tc;
    cin >> tc;
    while (tc--)
    {
        int V, E;
        cin >> V >>

            E;

        vector<int> adj[V];

        for (int i = 0; i < E; i++)
        {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
            // 		adj[v].push_back(u);
        }
        // string s1;
        // cin>>s1;
        Solution obj;
        vector<int> ans = obj.bfsOfGraph(V, adj);
        for (int i = 0; i < ans.size(); i++)
        {
            cout << ans[i] << " ";
        }
        cout << endl;
    }
    return 0;
}
// } Driver Code Ends