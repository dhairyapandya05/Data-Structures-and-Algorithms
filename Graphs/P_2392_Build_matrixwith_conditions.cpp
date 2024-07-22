class Solution {
public:
    vector<int> topo(vector<vector<int>>& conditions, int& k) {
        unordered_map<int, vector<int>> mp;
        vector<int> indegrees(k + 1, 0);
        vector<int> result;
        for (auto it : conditions) {
            mp[it[0]].push_back(it[1]);
            indegrees[it[1]]++;
        }
        queue<int> qe;
        for (int i = 1; i <= k; i++) {
            if (indegrees[i] == 0) {
                qe.push(i);
            }
        }
        while (!qe.empty()) {
            int n = qe.size();
            while (n--) {
                int frontele = qe.front();
                result.push_back(frontele);
                qe.pop();
                for (auto it : mp[frontele]) {
                    indegrees[it]--;
                    if (indegrees[it] == 0) {
                        qe.push(it);
                    }
                }
            }
        }
        if(result.size()!=k){
            return {};
        }
        return result;
    }
    vector<vector<int>> buildMatrix(int k, vector<vector<int>>& rowConditions,
                                    vector<vector<int>>& colConditions) {
        // we will have to form the topological sort of the functions
        vector<vector<int>> ans(k,vector<int>(k,0));
        vector<int> rowtopo = topo(rowConditions, k);
        vector<int> coltopo = topo(colConditions, k);
        if(rowtopo.empty() or coltopo.empty()){
            return {};// we have found a cycle so we cant form a matrix
        }
        for(int i=0;i<k;i++){
            for(int j=0;j<k;j++){
                if(rowtopo[i]==coltopo[j]){
                    ans[i][j]=rowtopo[i];
                }
            }
        }
        return ans;
    }
};