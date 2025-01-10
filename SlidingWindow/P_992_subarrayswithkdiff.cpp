class Solution
{
public:
    int slidingWindow(vector<int> &nums, int k)
    {
        int i = 0, j = 0, n = nums.size();
        int result = 0;
        unordered_map<int, int> mp;
        while (j < n)
        {
            mp[nums[j]]++;
            while (i <= j and mp.size() > k)
            {
                mp[nums[i]]--;
                if (mp[nums[i]] == 0)
                {
                    mp.erase(nums[i]);
                }
                i++;
            }
            result += (j - i + 1);
            j++;
        }
        return result;
    }
    int subarraysWithKDistinct(vector<int> &nums, int k)
    {
        return slidingWindow(nums, k) - slidingWindow(nums, k - 1);
    }
};

// Approach 2
// Great approach

class Solution
{
public:
    int slidingWindow(vector<int> &nums, int k)
    {
        int i = 0, j = 0, n = nums.size();
        int result = 0;
        int i_bada = 0;
        unordered_map<int, int> mp;
        while (j < n)
        {
            mp[nums[j]]++;
            while (i <= j and mp.size() > k)
            {
                mp[nums[i]]--;
                if (mp[nums[i]] == 0)
                {
                    mp.erase(nums[i]);
                }
                i++;
                i_bada = i;
            }
            // to find out the subarray ending at k with smallest length
            while (mp[nums[i]] > 1)
            {
                mp[nums[i]]--;
                i++;
            }
            if (mp.size() == k)
            {
                result += (i - i_bada + 1);
            }
            j++;
        }
        return result;
    }
    int subarraysWithKDistinct(vector<int> &nums, int k)
    {
        return slidingWindow(nums, k);
    }
};