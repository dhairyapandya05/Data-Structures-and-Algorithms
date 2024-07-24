class Solution {
public:
    typedef pair<int, int> pp;
    vector<int> getOrder(vector<vector<int>>& tasks) {
        vector<int> result;
        int n = tasks.size();
        vector<array<int, 3>> tasksprocess;
        priority_queue<pp, vector<pp>, greater<pp>> pq;
        long long currtime = 0;
        int processingtime = 0;
        for (int i = 0; i < n; i++) {
            tasksprocess.push_back({tasks[i][0], tasks[i][1], i});
        }
        sort(tasksprocess.begin(),tasksprocess.end());
        int i=0;
        while (i < n or !pq.empty()) {
            if (pq.empty() and tasksprocess[i][0] > currtime) {
                currtime = tasksprocess[i][0];
                // pq.push({tasksprocess[i][1], tasksprocess[i][2]});
            }
            while(i<n and tasksprocess[i][0]<=currtime){
                pq.push({tasksprocess[i][1], tasksprocess[i][2]});
                i++;
            }
            auto temp=pq.top();
            pq.pop();
            currtime+=temp.first;
            result.push_back(temp.second);
        }
        return result;
    }
};