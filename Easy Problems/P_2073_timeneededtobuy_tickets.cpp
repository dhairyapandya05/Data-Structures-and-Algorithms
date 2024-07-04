class Solution {
public:
    int timeRequiredToBuy(vector<int>& tickets, int k) {
        int time = 0;
        int n = tickets.size();

        while (tickets[k] > 0) {
            for (int i = 0; i < n; ++i) {
                if (tickets[i] > 0) {
                    tickets[i]--;
                    time++;
                }
                if (tickets[k] == 0) {
                    return time;
                }
            }
        }

        return time;

        //great solution
        // int time = 0;
        
        // for (int i = 0; i < tickets.size(); i++) {
            
        //     if (i <= k) {
        //         time += min(tickets[k], tickets[i]);
        //     } else {
        //         time += min(tickets[k] - 1, tickets[i]);
        //     }
        // }
        
        // return time;
    }
};