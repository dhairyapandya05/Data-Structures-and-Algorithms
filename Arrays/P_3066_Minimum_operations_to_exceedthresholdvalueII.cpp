class Solution {
public:
    int minOperations(vector<int> &nums, int k) {
        int n = nums.size();
        priority_queue<long long int, vector<long long int>, greater<long long int>> minHeap(nums.begin(), nums.end());
        int count = 0;
        while (minHeap.size() > 1 && minHeap.top() < k) {
            long long int first = minHeap.top();
            minHeap.pop();
            long long int second = minHeap.top();
            minHeap.pop();
            long long int newNum = first * 2 + second;

            minHeap.push(newNum);
            count++;
        }

        return count;
    }
};
