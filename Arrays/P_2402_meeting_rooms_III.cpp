#define ll long long
#define pi pair<ll, ll>

class Solution {
public:
    int mostBooked(int n, vector<vector<int>> &A) {
        vector<int> roomcnt(n, 0);
        set<int> s;
        priority_queue<pi, vector<pi>, greater<pi>> q;
        sort(A.begin(), A.end());
        int m = A.size();
        // store available rooms
        for (int i = 0; i < n; i++) {
            s.insert(i);
        }
        for (int i = 0; i < m; i++) {
            ll start = A[i][0];
            ll end = A[i][1];
            // storing available room in set
            while (q.size() > 0 && q.top().first <= start) {
                int room = q.top().second;
                q.pop();
                s.insert(room);
            }
            // delaying the current meeting
            if (s.size() == 0) {
                pair<ll, ll> p = q.top();
                q.pop();
                ll dif = end - start;
                start = p.first;
                end = start + dif;
                s.insert(p.second);
            }
            // lowest number of unsed room available
            auto it = s.begin();
            roomcnt[*it]++;
            // assign meeting to lowest avaible room
            q.push({end, *it});
            s.erase(*it);
        }
        int ans = 0;
        int maxi = 0;
        // find room with maximum meetings
        for (int i = 0; i < n; i++) {
            if (maxi < roomcnt[i]) {
                maxi = roomcnt[i];
                ans = i;
            }
        }
        return ans;
    }
};

// My code
class Solution {
public:
    int mostBooked(int n, vector<vector<int>> &meetings) {
        vector<int> roomUsedCount(n, 0);
        vector<long long> lastFreeTime(n, 0);
        sort(meetings.begin(), meetings.end());
        int m = meetings.size();
        for (int i = 0; i < m; i++) {
            int start = meetings[i][0];
            int end = meetings[i][1];
            int duration = end - start;
            bool found = false;
            long long earlyendRoomTime = LLONG_MAX;
            int earlyEndRoom = 0;
            for (int room = 0; room < n; room++) {
                if (start >= lastFreeTime[room]) {
                    found = true;
                    lastFreeTime[room] = end;
                    roomUsedCount[room]++;
                    break;
                }
                // also we will find out the minimum among them
                if (earlyendRoomTime > lastFreeTime[room]) {
                    earlyendRoomTime = lastFreeTime[room];
                    earlyEndRoom = room;
                }
            }
            if (!found) {
                lastFreeTime[earlyEndRoom] += duration;
                roomUsedCount[earlyEndRoom]++;
            }
        }
        int maxusedRoomIdx = (max_element(roomUsedCount.begin(), roomUsedCount.end()) - roomUsedCount.begin());
        return maxusedRoomIdx;
    }
};

//  Better Approach
class Solution {
public:
    int mostBooked(int n, vector<vector<int>> &meetings) {
        typedef pair<long long, int> P;

        int m = meetings.size();

        sort(begin(meetings), end(meetings)); // sort by starting time of meetings

        vector<int> roomsUsedCount(n, 0); // Each room is used 0 times in the beginning

        priority_queue<P, vector<P>, greater<P>> usedRooms;
        // To store {earliest room empty time, room No.}

        priority_queue<int, vector<int>, greater<int>> unusedRooms;
        // To store rooms that are used
        for (int room = 0; room < n; room++) {
            unusedRooms.push(room); // All rooms are unused in the beginning
        }

        for (vector<int> &meet : meetings) {
            int start = meet[0];
            int end = meet[1];

            // First see, by this time, which rooms can be empty now
            // And move them to unusedRooms
            // Pahalae jo jo bhi free honae vaalae hai usko allag sae unused room mae rakh daegae
            while (!usedRooms.empty() && usedRooms.top().first <= start) {
                int room = usedRooms.top().second;
                usedRooms.pop();
                unusedRooms.push(room);
            }

            if (!unusedRooms.empty()) {
                int room = unusedRooms.top();
                unusedRooms.pop();
                usedRooms.push({end, room});
                roomsUsedCount[room]++;
            } else { // We don't have any room available now. Pick earliest end room
                int room = usedRooms.top().second;
                long long endTime = usedRooms.top().first;
                usedRooms.pop();
                usedRooms.push({endTime + (end - start), room});
                roomsUsedCount[room]++;
            }
        }

        int resultRoom = -1;
        int maxUse = 0;
        for (int room = 0; room < n; room++) {
            if (roomsUsedCount[room] > maxUse) {
                maxUse = roomsUsedCount[room];
                resultRoom = room;
            }
        }

        return resultRoom;
    }
};

// O(m)*log(n)