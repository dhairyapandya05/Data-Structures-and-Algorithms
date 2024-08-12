class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int n=cost.size();
        for(int i=0;i<n;i++){
            if(cost[i]>gas[i]){
                continue;
            }
            int currGas=0;
            int costofGoingToNextStation=cost[i];
            int j=(i+1)%n;
            currGas=gas[i]-costofGoingToNextStation;
            currGas+=gas[j];
            while(j!=i){
                if(cost[j]>currGas){
                    break;
                }
                int costfrommovingfromjstation=cost[j];
                j=(j+1)%n;
                currGas=currGas-costfrommovingfromjstation+gas[j];
            }
            if(j==i){
                return i;
            }
        }
        return -1;
    }
};

//Approach 2

class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int n=gas.size();
        int totalcost=accumulate(cost.begin(),cost.end(),0);
        int totalgas=accumulate(gas.begin(),gas.end(),0);
        if(totalcost>totalgas){
            return -1;// no possible answer could be found
        }
        // if the code recaches this particular iteration then it is evident that there is definately a answer possible
        // so we will start iterating them 
        int total=0;
        int result=0;
        for(int i=0;i<n;i++){
            total+=gas[i]-cost[i];
            if(total<0){
                total=0;
                result=i+1;
            }

        }
        return result;
    }
};// greedy approach