class Solution
{
public:
    int numSubarraysWithSum(vector<int> &nums, int goal)
    {
        unordered_map<int, int> count;
        count[0] = 1;
        int curr_sum = 0;
        int total_subarrays = 0;

        for (int num : nums)
        {
            curr_sum += num;
            if (count.find(curr_sum - goal) != count.end())
            {
                total_subarrays += count[curr_sum - goal];
            }
            count[curr_sum]++;
        }

        return total_subarrays;
    }
};

// By sliding window
class Solution
{
public:
    int numSubarraysWithSum(vector<int> &nums, int goal)
    {
        int n = nums.size();
        int i = 0, j = 0;
        int currSum = 0;
        int countZeros = 0;
        int result = 0;
        while (j < n)
        {
            currSum += nums[j];
            while (i < j and (nums[i] == 0 or currSum > goal))
            { // Important: i<j condition is vvvv important
                if (nums[i] == 0)
                {
                    countZeros++;
                }
                else
                {
                    countZeros = 0;
                }
                currSum -= nums[i];
                i++;
            }
            if (currSum == goal)
            {
                result += 1 + countZeros;
            }
            j++;
        }
        return result;
    }
};