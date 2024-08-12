class Solution {
public:
    int solve(int i, int j, string& word1, string& word2) {
        if (i >= word1.length()) {
            return word2.length() - j;
        }
        if (j >= word2.length()) {
            return word1.length() - i;
        }
        int ans;
        if (word1[i] == word2[j]) {
            ans = solve(i + 1, j + 1, word1, word2);
        } else {
            int insertion = 1 + solve(i, j + 1, word1, word2);
            int deletion = 1 + solve(i + 1, j, word1, word2);
            int replace = 1 + solve(i + 1, j + 1, word1, word2);
            ans = min({insertion, deletion, replace});
        }
        return ans;
    }
    int minDistance(string word1, string word2) {
        int ans = solve(0, 0, word1, word2);
        return ans;
    }
};