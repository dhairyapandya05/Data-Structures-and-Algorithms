class Solution
{
public:
    int numSubarrayProductLessThanK(vector<int> &nums, int k)
    {
        int i = 0, j = 0;
        if (k <= 1)
        {
            return 0;
        }
        int n = nums.size();
        int count = 0;
        long long sum = 1;
        while (j < n)
        {
            sum *= nums[j];
            while (sum >= k)
            {
                sum /= nums[i];
                i++;
            }
            count += (j - i + 1); // Important: Number of subarrays ending at j
            j++;
        }
        return count;
    }
};