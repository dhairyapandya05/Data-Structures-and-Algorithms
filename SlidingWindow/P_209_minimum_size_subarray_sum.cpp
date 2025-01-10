class Solution
{
public:
    void solve(int target, vector<int> &nums, int &minLen)
    {
        int i = 0, j = 0;
        int n = nums.size();
        int sum = 0;
        while (j < n)
        {
            sum += nums[j];
            while (sum >= target)
            {
                minLen = min(minLen, j - i + 1);
                sum -= nums[i];
                i++;
            }
            j++;
        }
    }
    int minSubArrayLen(int target, vector<int> &nums)
    {
        int minLen = INT_MAX;
        solve(target, nums, minLen);
        return (minLen == INT_MAX) ? 0 : minLen;
    }
};