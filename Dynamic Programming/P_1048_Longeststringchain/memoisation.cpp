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

    int solve(int prev, int curr, vector<string>& words,
              vector<vector<int>>& dp) {
        if (curr >= words.size()) {
            return 0;
        }
        if (prev != -1 and dp[prev][curr] != -1) {
            return dp[prev][curr];
        }
        int take = 0, skip;
        if (prev == -1 or isPredecessor(words[prev], words[curr])) {
            take = 1 + solve(curr, curr + 1, words, dp);
        }
        skip = solve(prev, curr + 1, words, dp);
        if (prev == -1) {
            return max(take, skip);
        }
        return dp[prev][curr] = max(take, skip);
    }
    int longestStrChain(vector<string>& words) {
        auto lambda = [&](string a, string b) {
            return a.length() < b.length();
        };
        sort(words.begin(), words.end(), lambda);
        int n = words.size();
        vector<vector<int>> dp(n + 1, vector<int>(n + 1, -1));
        int ans = solve(-1, 0, words, dp);
        return ans;
    }
};