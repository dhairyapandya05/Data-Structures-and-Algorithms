class Solution {
public:
    bool isPredecessor(string& prev, string& curr) {
        int N = prev.length();
        int M = curr.length();
        if (N >= M or M - N != 1) {
            return false;
        }
        int i = 0;
        int j = 0;
        while (i < N and j < M) {
            if (prev[i] == curr[j]) {
                i++;
            }
            j++;
        }
        return i == N;
    }

    int longestStrChain(vector<string>& words) {
        auto lambda = [&](string a, string b) {
            return a.length() < b.length();
        };
        sort(words.begin(), words.end(), lambda);
        int n = words.size();
        vector<int> t(n, 1);
        int maxlis = 1;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < i; j++) {
                if (isPredecessor(words[j],words[i])) {
                    t[i] = max(t[j] + 1, t[i]);
                    maxlis = max(maxlis, t[i]);
                }
            }
        }
        return maxlis;
    }
};