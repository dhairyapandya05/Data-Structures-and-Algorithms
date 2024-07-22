//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
    public:
    vector<int> parent;
    vector<int> rank;
    
    int find(int i){
        if(parent[i]==i){
            return i;
        }
        return parent[i]=find(parent[i]);
    }
    
    void unionSets(int u,int v){
        int x_parent=find(u);
        int y_parent=find(v);
        if(x_parent!=y_parent){
            if(rank[x_parent] > rank[y_parent]){
                parent[y_parent]=x_parent;
            }
            else if(rank[x_parent] < rank[y_parent]){
                parent[x_parent]=y_parent;
            }
            else{
                parent[x_parent]=y_parent;
                rank[y_parent]++;
            }
        }
    }
    
    //Function to detect cycle using DSU in an undirected graph.
	int detectCycle(int V, vector<int>adj[])
	{
	    // Code here
	    parent.resize(V);
	    rank.resize(V,0);
	    for(int i = 0; i<V; i++){
	        parent[i] = i;
	        rank[i]=1;
	    }
// Understanding the if (u < v) Condition:
// In an undirected graph, an edge between two vertices u and v appears in both adjacency lists: adj[u] and adj[v]. For example, if there is an edge between vertex 0 and vertex 1, then:

// Vertex 0's adjacency list will contain vertex 1 (adj[0] will have 1).
// Vertex 1's adjacency list will contain vertex 0 (adj[1] will have 0).
// Why Use if (u < v)?
// Avoid Redundant Processing:

// Without the condition if (u < v), the algorithm would process each edge twice: once as (u, v) and once as (v, u).
By checking if (u < v), we ensure that each edge is processed only once. This is because for any edge (u, v), either u < v or u > v, and we choose to process it only in the case where u < v.   
	    for(int u=0;u<V;u++){
	        for(auto& v: adj[u]){
	            if(u<v){
	                int u_parent=find(u);
	                int v_parent=find(v);
	                if(u_parent==v_parent){
	                    return true;// cycle is present
	                }
	                else{
	                    unionSets(u_parent,v_parent);
	                }
	            }
	        }
	    }
	    return false;
	}
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int V, E;
		cin >> V >> E;
		vector<int>adj[V];
		for(int i = 0; i < E; i++){
			int u, v;
			cin >> u >> v;
			adj[u].push_back(v);
			adj[v].push_back(u);
		}
		Solution obj;
		int ans = obj.detectCycle(V, adj);
		cout << ans <<"\n";	}
	return 0;
}
// } Driver Code Ends
// link:https://www.geeksforgeeks.org/problems/detect-cycle-using-dsu/1