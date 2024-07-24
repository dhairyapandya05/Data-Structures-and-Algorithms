class Solution {
public:
    int minStoneSum(vector<int>& piles, int k) {
        priority_queue<int> pq;
        int cnt = 0;
        for (auto& t : piles) {
            pq.push(t);
            cnt += t;
        }
        int sum = cnt;
        for (int i = 0; i < k; i++) {
            int value = pq.top();
            pq.pop();
            sum = sum - value + (value + 1) / 2;
            cout << sum << endl;
            pq.push((value + 1) / 2);
        }
        return sum;
    }
};