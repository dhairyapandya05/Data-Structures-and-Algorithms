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
	        
	    for(int u=0;u<V;u++){
	        for(auto& v: adj[u]){
	            if(u<v){
	                int u_parent=find(u);
	                int v_parent=find(v);
	                if(u_parent==v_parent){
	                    return true;
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