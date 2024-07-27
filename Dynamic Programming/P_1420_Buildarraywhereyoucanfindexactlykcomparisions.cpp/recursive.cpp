class Solution {
public:
    int MOD = 1e9 + 7;
    int size;
    int range;
    int totalcost;
    int solve(int idx, int cost, int maxelement) {
        // base case
        if (idx == size) {
            if (cost == totalcost) {
                return 1;
            }
            return 0;
        }
        int result = 0;
        for (int i = 1; i <= range; i++) {
            if (i > maxelement) {
                result = (result + solve(idx + 1, cost+1, i)) % MOD;
            } else {
                result = (result + solve(idx + 1, cost, maxelement)) % MOD;
            }
        }
        return result;
    }
    int numOfArrays(int n, int m, int k) {
        size = n;
        range = m;
        totalcost = k;
        return solve(0, 0, -1);
    }
};