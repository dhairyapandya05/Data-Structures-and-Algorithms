class Solution {
public:
    int maximumBags(vector<int>& capacity, vector<int>& rocks, int additionalRocks) {
        priority_queue<int,vector<int>,greater<int>>pq;
        int n=rocks.size();
        for(int i=0;i<n;i++){
            pq.push(capacity[i]-rocks[i]);
        }
        int cnt=0;
        while(!pq.empty() and additionalRocks-pq.top()>=0){
            additionalRocks-=pq.top();
            pq.pop();
            cnt++;
        }
        return cnt;
    }
};