class Solution {
public:
    double averageWaitingTime(vector<vector<int>> &customers) {
        int numberofcustomers = customers.size();
        int dishpreparestarttime = 0;
        int dishprparetime;
        int dishcompletiontime;
        double waitingtime = 0;
        for (int i = 0; i < numberofcustomers; i++) {
            int originalarrivaltime = customers[i][0];
            dishpreparestarttime = max(dishpreparestarttime, originalarrivaltime);
            dishprparetime = customers[i][1];
            dishcompletiontime = dishpreparestarttime + dishprparetime;
            waitingtime += dishcompletiontime - originalarrivaltime;
            dishpreparestarttime = dishcompletiontime;
        }
        return waitingtime / numberofcustomers;
    }
};

// With easier variable naming
class Solution {
public:
    double averageWaitingTime(vector<vector<int>> &customers) {
        int n = customers.size();

        double totalWaitTime = 0;
        int currTime = 0;

        for (auto &vec : customers) {
            int arrivalTime = vec[0];
            int cookTime = vec[1];

            if (currTime < arrivalTime) {
                currTime = arrivalTime;
            }

            int waitTime = currTime + cookTime - arrivalTime;

            totalWaitTime += waitTime;

            currTime += cookTime;
        }

        return totalWaitTime / n;
    }
};