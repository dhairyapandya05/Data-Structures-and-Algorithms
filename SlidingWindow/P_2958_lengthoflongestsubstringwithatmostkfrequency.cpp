// Khandani Template

class Solution
{
public:
    int maxSubarrayLength(vector<int> &nums, int k)
    {
        int i = 0, j = 0, result = 0, n = nums.size();
        unordered_map<int, int> mp;
        while (j < n)
        {
            mp[nums[j]]++;
            while (i < j and mp[nums[j]] > k)
            {
                mp[nums[i]]--;
                i++;
            }
            result = max(result, j - i + 1);
            j++;
        }
        return result;
    }
};

// Method 2 through culprit element index
class Solution
{
public:
    int maxSubarrayLength(vector<int> &nums, int k)
    {
        int i = 0, j = 0, result = 0, n = nums.size();
        int culprit = 0;
        unordered_map<int, int> mp;
        while (j < n)
        {
            mp[nums[j]]++;
            if (mp[nums[j]] == k + 1)
            {
                culprit++;
            }
            if (culprit > 0)
            {
                mp[nums[i]]--;
                if (mp[nums[i]] == k)
                {
                    culprit--;
                }
                i++;
            }
            if (culprit == 0)
                result = max(result, j - i + 1);
            j++;
        }
        return result;
    }
};