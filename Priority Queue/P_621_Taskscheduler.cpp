class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        vector<int> vec(26, 0);
        int time = 0;
        for (auto& ch : tasks) {
            vec[ch - 'A']++;
        }
        priority_queue<int> pq;
        for (int i = 0; i < 26; i++) {
            if (vec[i] > 0) {
                pq.push(vec[i]);
            }
        }
        while (!pq.empty()) {
            vector<int> temp;

            for (int i = 1; i <= n + 1; i++) {
                if (!pq.empty()) {
                    int freq = pq.top();
                    pq.pop();
                    freq--;
                    temp.push_back(freq);
                }
            }
            // aab jo bhi processed taks the vo humnae vector mae store kar dia
            // hai aab usko priority queue mae daalaegae jiski frequency >0 hogi
            // usko
            for (auto& i : temp) {
                if (i > 0) {
                    pq.push(i);
                }
            }
            if (pq.empty()) { // all the processes are finished
                time += temp.size();
            } else {
                time += (n + 1);
            }
        }
        return time;
    }
};