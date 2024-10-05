class Solution
{

public:
    const int MOD = 1000000007;
    int perfectSum(int arr[], int n, int sum)
    {
        vector<vector<int>> dp(n + 1, vector<int>(sum + 1, 0));
        for (int i = 0; i <= n; i++)
        {
            dp[i][0] = 1;
        }

        // Handle the first element
        if (arr[0] == 0)
            dp[1][0] = 2; // Two ways to form sum 0 (include or exclude 0)
        else
            dp[1][0] = 1; // One way to form sum 0 if arr[0] != 0

        if (arr[0] <= sum)
            dp[1][arr[0]] = 1; // If the first element is less than or equal to sum

        // Fill the rest of the dp table
        for (int i = 2; i <= n; i++)
        {
            for (int summ = 0; summ <= sum; summ++)
            {
                int nottake = dp[i - 1][summ];
                int take = 0;
                if (summ - arr[i - 1] >= 0)
                {
                    take = dp[i - 1][summ - arr[i - 1]];
                }
                dp[i][summ] = (take + nottake) % MOD;
            }
        }

        return dp[n][sum] % MOD;
    }
};