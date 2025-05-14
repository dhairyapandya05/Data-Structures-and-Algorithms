class Solution {
public:
    int minimumRecolors(string blocks, int k) {
        int n = blocks.length();
        if (k > n)
            return -1; // not possible
        vector<int> prefixW(n, 0);
        int cnt = 0;
        for (int i = 0; i < n; i++) {
            if (blocks[i] == 'W') {
                cnt++;
            }
            prefixW[i] = cnt;
        }
        int minchange = prefixW[k - 1];
        for (int i = k; i < n; i++) {
            minchange = min(minchange, prefixW[i] - prefixW[i - k]);
        }
        return minchange;
    }
};