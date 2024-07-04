// link:https://www.geeksforgeeks.org/problems/strongly-connected-components-kosarajus-algo/1
class Solution
{
	public:
	void dfstraversal(int v,vector<bool>& visitedrev,vector<vector<int>>& revadj){
	    visitedrev[v]=true;
	    for(auto adj_v:revadj[v]){
	        if(visitedrev[adj_v]==false){
	            dfstraversal(adj_v,visitedrev,revadj);
	        }
	    }
	}
	void dfs(int u,vector<bool>& visited,vector<vector<int>>& adj,stack<int>& st){
	    visited[u]=true;
	    for(auto v:adj[u]){
	        if(visited[v]==false){
	            dfs(v,visited,adj,st);
	        }
	    }
	    st.push(u);
	}
	//Function to find number of strongly connected components in the graph.
    int kosaraju(int V, vector<vector<int>>& adj)
    {
        stack<int> st;
        vector<bool> visited (V,false);
        for(int i=0;i<V;i++){
            if(visited[i]==false){
                dfs(i,visited,adj,st);
            }
        }
        
    // step 2 Reverse the directions of the graph
    vector<bool>visitedrev(V,false);
    vector<vector<int>> revadj;
    for(int u=0;u<V;u++){
        for(auto v:adj[u]){
            revadj[v].push_back(u);
        }
    } 
    
    // Step 3
    // dfs traversal based on the stack order
    int components=0;
    while(!st.empty()){
        int temp=st.top();
        st.pop();
        if(visitedrev[temp]==false){
            dfstraversal(temp,visitedrev,revadj);
            components++;
        }
        
    }
        return components;
    }
};