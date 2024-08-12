//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
    
    
	public:
	
	vector<int> parent;
    vector<int> rank;
    int find(int u){
        if(parent[u]==u){
            return parent[u];
        }
        return parent[u]=find(parent[u]);
    }
    
    void Union(int v,int u){
        int u_parent=find(u);
        int v_parent=find(v);
        if(u_parent==v_parent){
            return;
        }
        else{
            if(rank[u_parent]>rank[v_parent]){
                parent[v_parent]=u_parent;
                // rank[v_parent]++;
            }
            else if(rank[v_parent]>rank[u_parent]){
                parent[u_parent]=v_parent;
                // rank[u_parent]++;
            }
            else{
                parent[u_parent]=v_parent;
                rank[v_parent]++;
            }
        }
    }
    
    int KruscalsAlgo(vector<vector<int>>& vec){
        
        
        
        int sum=0;
        for(auto& temp:vec){
            int u=temp[0];
            int v=temp[1];
            int w=temp[2];
            int u_parent=find(u);
            int v_parent=find(v);
            if(u_parent!=v_parent){
                Union(u_parent,v_parent);
                sum+=w;
            }
        }
        return sum;
    }

	//Function to find sum of weights of edges of the Minimum Spanning Tree.
    int spanningTree(int V, vector<vector<int>> adj[])
    {

        rank.resize(V,0);
        parent.resize(V);
        for(int i=0;i<V;i++){
            parent[i]=i;
        }
        // code here
        vector<vector<int>> vec;
        for(int u=0;u<V;u++){
            for(auto& temp:adj[u]){
                int v=temp[0];
                int w=temp[1];
                vec.push_back({u,v,w});
            }
        }
        auto comparator=[](vector<int>& v1,vector<int>& v2){
            return v1[2] < v2[2];
        };
        sort(vec.begin(),vec.end(),comparator);
        int ans=KruscalsAlgo(vec);
        return ans;
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

// link:https://www.geeksforgeeks.org/problems/minimum-spanning-tree/1
// } Driver Code Ends