class Solution {
public:
    long long totalCost(vector<int>& costs, int k, int candidates) {
        priority_queue<int, vector<int>, greater<int>> pq1;
        priority_queue<int, vector<int>, greater<int>> pq2;
        long long totalcost=0;
        int hiring=0;
        int n=costs.size();
        int i=0,j=n-1;
        while(hiring<k){
            while(pq1.size()<candidates and i<=j){
                pq1.push(costs[i]);
                i++;
            }
            while(pq2.size()<candidates and i<=j){
                pq2.push(costs[j]);
                j--;
            }
            int minpq1=(pq1.empty())?INT_MAX:pq1.top();
            int minpq2=(pq2.empty())?INT_MAX:pq2.top();
            if(minpq1<=minpq2){
                hiring++;
                totalcost+=minpq1;
                pq1.pop();
            }
            else{
                hiring++;
                pq2.pop();
                totalcost+=minpq2;

            }
        }
        return totalcost;
    }
};