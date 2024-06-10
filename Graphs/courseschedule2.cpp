class Solution {
public:
    void solution(unordered_map<int, vector<int>>& adj, vector<int> indegree,
                  vector<bool>& visited, vector<int>& result) {
        queue<int> q;
        for (int i = 0; i < indegree.size(); i++) {
            if (indegree[i] == 0) {
                q.push(i);
            }
        }
        while(!q.empty()){
            int n=q.size();
            while(n--){
                int temp=q.front();
                q.pop();
                result.push_back(temp);
                for(auto&v:adj[temp]){
                    indegree[v]--;
                    if(indegree[v]==0){
                        q.push(v);
                    }
                }
            }
        }
    }
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        unordered_map<int, vector<int>> adj;
        vector<int> indegree(numCourses, 0);
        for (auto& temp : prerequisites) {
            int u = temp[1];
            int v = temp[0];
            adj[u].push_back(v);
            indegree[v]++;
        }
        vector<bool> visited(numCourses, false);
        vector<int> result;
        solution(adj, indegree, visited, result);
        if (result.size() == numCourses) {
            return result;
        }
        return {};
    }
};