class Solution {
public:
    long long maximumHappinessSum(vector<int>& happiness, int k) {
        priority_queue<int>pq(happiness.begin(),happiness.end());
        int i=0;
        long long totalhappiness=0;
        while(k--){
            int happiness=pq.top()-i;
            totalhappiness+=max(happiness,0);
            pq.pop();
            i++;// decrease the happiness
        }
        return totalhappiness;
    }
};