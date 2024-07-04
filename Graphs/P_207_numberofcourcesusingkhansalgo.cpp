// class Solution {
// public:
//     void solve_bfs(unordered_map<int, vector<int>>& adj, vector<bool>& visited,
//                    vector<int>& result, vector<int> indegree) {
//         queue<int> q;
//         for (int i = 0; i < indegree.size(); i++) {
//             if (indegree[i] == 0) {
//                 q.push(i);
//             }
//         }

//         while (!q.empty()) {
//             int n = q.size();
//             while (n--) {
//                 int temp = q.front();
//                 q.pop();
//                 visited[temp] = true;
//                 result.push_back(temp);
//                 for (auto& v : adj[temp]) {
//                     indegree[v]--;
//                     if (indegree[v] == 0) {
//                         q.push(v);
//                     }
//                 }
//             }
//         }
//     }
//     bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
//         unordered_map<int, vector<int>> adj;
//         vector<int> indegree(numCourses, 0);

//         for (auto it : prerequisites) {
//             int v = it[0];
//             int u = it[1];
//             adj[u].push_back(v);
//             indegree[v]++;
//         }
//         vector<bool> visited(numCourses, false);
//         vector<int> result;
//         // for (int i = 0; i < numCourses; i++) {
//         //     if (visited[i] == false) {
//                 solve_bfs(adj, visited, result, indegree);
//         //     }
//         // }
//         if (result.size() == numCourses) {
//             return true;//I was able to complete all teh courses 
//         } else {
//             return false;//I was not able to complete all the courses as there was a cycle so not all the courses could be completed
//         }
//     }
// };


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