class Solution {
public:
    int maxIceCream(vector<int>& costs, int coins) {
        sort(costs.begin(),costs.end());
        int cnt=0;
        int i=0;
        int rs=0;
        int n=costs.size();
        while(i<n and costs[i]+rs<=coins){
            rs+=costs[i];
            cnt++;
            i++;
        }
        return cnt;
    }
};