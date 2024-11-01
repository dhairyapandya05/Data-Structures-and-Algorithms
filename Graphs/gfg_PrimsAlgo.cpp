//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
    typedef pair<int,int> pp;// weight node
	public:
	//Function to find sum of weights of edges of the Minimum Spanning Tree.
    int spanningTree(int V, vector<vector<int>> adj[])
    {
        // code here
        priority_queue<pp,vector<pp>,greater<pp>> pq;
        vector<bool> visited (V,false);
        pq.push({0,0});
        int sum=0;
        // visited[0]=true;
        while(!pq.empty()){
            auto temp = pq.top();
            pq.pop();
            int wt=temp.first;
            int node=temp.second;
            
            if(visited[node]==true){
                continue;
            }
            
            visited[node]=true;
            sum+=wt;
            for(auto& dt:adj[node]){
                int v=dt[0];
                int w=dt[1];
                if(visited[v]==false){
                    pq.push({w,v});
                }
            }
        }
        return sum;
    }
};

//{ Driver Code Starts.


int main()
{
    int t;
    cin >> t;
    while (t--) {
        int V, E;
        cin >> V >> E;
        vector<vector<int>> adj[V];
        int i=0;
        while (i++<E) {
            int u, v, w;
            cin >> u >> v >> w;
            vector<int> t1,t2;
            t1.push_back(v);
            t1.push_back(w);
            adj[u].push_back(t1);
            t2.push_back(u);
            t2.push_back(w);
            adj[v].push_back(t2);
        }
        
        Solution obj;
    	cout << obj.spanningTree(V, adj) << "\n";
    }

    return 0;
}

// link:https://www.geeksforgeeks.org/problems/minimum-spanning-tree/1?itm_source=geeksforgeeks&itm_medium=article&itm_campaign=bottom_sticky_on_article
// } Driver Code Ends