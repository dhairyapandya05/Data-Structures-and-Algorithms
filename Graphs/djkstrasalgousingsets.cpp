//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
	public:
	//Function to find the shortest distance of all the vertices
    //from the source vertex S.
    vector <int> dijkstra(int V, vector<vector<int>> adj[], int S)
    {
        // Code here
        vector<int> result (V,INT_MAX);
        set<pair<int,int>> st;
        st.insert({S,0});
        result[S]=0;
        while(!st.empty()){
            auto& it=*st.begin();
            int node=it.first;
            int dist=it.second;
            st.erase(it);
            for(auto&v:adj[node]){
                int adjnode=v[0];
                int wt=v[1];
                if(wt+dist<result[adjnode]){
                    if(result[adjnode]!=INT_MAX){
                        st.erase({adjnode,result[adjnode]});
                    }
                    result[adjnode]=wt+dist;
                    st.insert({adjnode,wt+dist});
                }
            }
        }
        return result;
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
        int S;
        cin>>S;
        
        Solution obj;
    	vector<int> res = obj.dijkstra(V, adj, S);
    	
    	for(int i=0; i<V; i++)
    	    cout<<res[i]<<" ";
    	cout<<endl;
    }

    return 0;
}


// } Driver Code Ends



for(int i=0;i<A.size();i++){
int Achar=A[i]-'0';
int Bchar=B[i]-'0';
if(Achar==Bchar){
    continue;
}
else if (Achar>Bchar){
    cout<<"A is bigger";
    break;
}
else{
    cout<<"B is bigger";
    break;
}
}