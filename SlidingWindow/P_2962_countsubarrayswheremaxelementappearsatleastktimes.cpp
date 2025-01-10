class Solution
{
public:
    long long countSubarrays(vector<int> &nums, int k)
    {
        int n = nums.size();
        int maxEle = *max_element(nums.begin(), nums.end());
        int count = 0, i = 0, j = 0;
        long long result = 0;
        while (j < n)
        {
            if (nums[j] == maxEle)
            {
                count++;
            }
            while (count >= k)
            { // Important: here i<j condition is not working but we can surely add i<=j condition because here k=1 which is most important
                result += n - j;
                if (nums[i] == maxEle)
                {
                    count--;
                }
                i++;
            }
            j++;
        }
        return result;
    }
};

// Importance:
/*

[28,5,58,91,24,91,53,9,48,85,16,70,91,91,47,91,61,4,54,61,49]
k=1

Output is 182 but its correct answer is 187
*/

// Approach 2
class Solution
{
public:
    long long countSubarrays(vector<int> &nums, int k)
    {
        int maxEle = *max_element(nums.begin(), nums.end());
        int n = nums.size();
        long long result = 0;
        vector<int> maxIndex;
        for (int i = 0; i < n; i++)
        {
            if (nums[i] == maxEle)
            {
                maxIndex.push_back(i);
            }
            int size = maxIndex.size();
            if (size >= k)
            {
                int lastIdx = maxIndex[size - k];
                result += lastIdx + 1;
            }
        }
        return result;
    }
};