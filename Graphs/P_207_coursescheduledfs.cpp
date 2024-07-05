class Solution {
public:
    bool solve(int u,vector<bool>& visited,unordered_map<int,vector<int>>& adj,vector<bool>& inRecursion){
        visited[u]=true;
        inRecursion[u]=true;
        for(auto& v:adj[u]){
            if(visited[v]==false){
                bool ans= solve(v,visited,adj,inRecursion);
                if(ans){
                    return true;//cycle is present
                }
            }
            else{
                if(inRecursion[v]==true){
                    return true;
                }
            }
        }
        inRecursion[u]=false;
        return false;
    }
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        unordered_map<int, vector<int>> adj;
        for (auto temp : prerequisites) {
            int u = temp[1];
            int v = temp[0];
            adj[u].push_back(v);
        }
        vector<bool> visited(numCourses, false);
        vector<bool> inRecursion(numCourses, false);

        for (int i = 0; i < numCourses; i++) {
            if (visited[i] == false) {
                bool ans = solve(i, visited, adj, inRecursion);
                if(ans==true){
                    return false;//course hum complete kar nahi kar saktae hai  
                }

            }
        }
        return true;
    }
};