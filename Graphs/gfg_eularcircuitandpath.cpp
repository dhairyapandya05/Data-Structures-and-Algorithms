//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
public:
    void DFS(vector<int>adj[], int u, vector<bool>& visited) {
        visited[u] = true;
        
        for(auto it = adj[u].begin(); it != adj[u].end(); it++) {
            if(visited[*it] == false) {
                DFS(adj, *it, visited);
            }
        }
    }
    bool isConnected(int V, vector<int>adj[]) {
        vector<bool> visited(V, false);
        
        //Find a vertex with non-zero degree
        int nonZeroDegreeVertex = -1;
        for(int i = 0; i<V; i++) {
            if(adj[i].size() != 0) {
                nonZeroDegreeVertex = i;
                break;
            }
        }
        
        // Start DFS traversal from a vertex with non-zero degree
        DFS(adj, nonZeroDegreeVertex, visited);
        
        // Check if all non-zero degree vertices are visited
        for(int i = 0; i<V; i++) {
            if(visited[i] == false && adj[i].size() > 0)
                return false;
        }
        return true;
    }

	int isEulerCircuit(int V, vector<int>adj[]){
	    // Code here
	    //Check if all non-zero degree vertices are connected
	    if(isConnected(V, adj) == false) {
	        return 0; //Non-Eulerian
	    }
	    
	    //Count vertices with odd degree
	    int oddCount = 0;
	    for(int i = 0; i<V; i++) {
	        if(adj[i].size()%2 != 0) {
	            oddCount++;
	        }
	    }
	    
	    // If count is more than 2, then graph is not Eulerian
        if (oddCount > 2)
            return 0; //Non-Eulerian
        
        if(oddCount == 2) {
            return 1; //Semi-Eulerian (It has only Euler Path)
        }
        
        return 2; //(Euler Circuit)
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
		int ans = obj.isEulerCircuit(V, adj);
		cout << ans <<"\n";	}
	return 0;
}
// } Driver Code Ends