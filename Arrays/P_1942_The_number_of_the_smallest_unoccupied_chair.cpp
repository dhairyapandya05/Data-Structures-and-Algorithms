class Solution {
public:
    typedef pair<int, int> p;
    int smallestChair(vector<vector<int>> &times, int targetFriend) {
        int n = times.size();
        vector<int> status(n, 0);
        priority_queue<p, vector<p>, greater<p>> pq;
        int targetArrival = times[targetFriend][0];
        auto cmp = [&](vector<int> &v1, vector<int> &v2) {
            return v1[0] < v2[0];
        };
        sort(times.begin(), times.end(), cmp);
        int i = 0;
        while (i < n) {
            while (!pq.empty() and times[i][0] >= pq.top().first) {
                status[pq.top().second] = 0;
                pq.pop();
            }
            auto it = find(status.begin(), //status.end(), 0);//Important: aAAGAR YAE HAMAE find na karna padae to hamae 2 minHeap laeni padaegi 
            int chair = it - status.begin();
            // Find the smallest available chair

            // If this is the target friend, return the chair number
            if (times[i][0] == targetArrival) {
                return chair;
            }
            status[chair] = 1; // occupies
            pq.push({times[i][1], chair});
            i++;
        }
        return -1;
    }
};

// Approach-2 (Naive O(n^2) approach that comes to mind first)
// T.C : O(n^2)
// S.C : O(n)
class Solution {
public:
    int smallestChair(vector<vector<int>> &times, int targetFriend) {
        int n = times.size();

        vector<int> endTimes(n, -1); // at max we will have 0 to n-1 chairs

        /*
            We need to sort the times based on arrival time but we don't want to
            loose the friend number after sorting. So, store the arrival time
            of targetFriend because it's given in the question that
            Each arrival time is distinct.
        */

        int targetArrivalTime = times[targetFriend][0];

        sort(begin(times), end(times));

        for (vector<int> &time : times) {
            int arrival = time[0];
            int depart = time[1];
            // Find the first unoccupied chair
            for (int i = 0; i < n; i++) {
                if (endTimes[i] <= arrival) {
                    endTimes[i] = depart; // update with current friend depart time

                    if (arrival == targetArrivalTime)
                        return i;
                    break;
                }
            }
        }
        return -1;
    }
};