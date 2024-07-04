class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        unordered_map<int,vector<int>> adj;
        for(auto it:prerequisites){
            int v=it[0];
            int u=it[1];
            adj[u]=v;
        }
        return solve(adj);
    }
};