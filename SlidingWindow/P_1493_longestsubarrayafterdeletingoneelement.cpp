class Solution
{
public:
    int maxResult(vector<int> &nums, int idxtoremove)
    {
        int cnt = 0;
        int maxcnt = 0;
        for (int i = 0; i < nums.size(); i++)
        {
            if (i == idxtoremove)
            {
                continue;
            }
            if (nums[i] == 1)
            {
                cnt++;
                maxcnt = max(maxcnt, cnt);
            }
            else
            {
                cnt = 0;
            }
        }
        return maxcnt;
    }
    int longestSubarray(vector<int> &nums)
    {
        int result = 0;
        int zero = 0;
        int n = nums.size();
        for (int i = 0; i < n; i++)
        {
            if (nums[i] == 0)
            {
                zero++;
                result = max(result, maxResult(nums, i));
            }
        }
        return (zero == 0) ? n - 1 : result;
    }
};

// Approach 2 using sliding window
int longestSubarray(vector<int> &nums)
{
    int n = nums.size();
    int zerocnt = 0;
    int result = 0;
    int i = 0;
    for (int j = 0; j < n;)
    {
        if (nums[j] == 0)
        {
            zerocnt++;
        }
        while (zerocnt > 1)
        {
            if (nums[i] == 0)
            {
                zerocnt--;
            }
            i++;
        }
        result = max(result, j - i); // Important: here j-i+1 but we have to delete one element so j-i+1-1 is j-i itself
        j++;
    }
    return result;
}
}
;

// using my way
class Solution
{
public:
    int longestSubarray(vector<int> &nums)
    {
        vector<int> cmp;
        cmp.push_back(-1);
        int n = nums.size();
        for (int i = 0; i < n; i++)
        {
            if (nums[i] == 0)
            {
                cmp.push_back(i);
            }
        }
        cmp.push_back(n);
        int maxi = 0;
        int m = cmp.size();
        if (m == n + 2)
        {
            return 0;
        }
        for (int i = 1; i < m - 1; i++)
        {
            maxi = max(maxi, (cmp[i] - cmp[i - 1]) + (cmp[i + 1] - cmp[i]) - 2);
        }
        return (maxi == 0) ? n - 1 : maxi;
    }
};

// method 2
class Solution
{
public:
    int longestSubarray(vector<int> &nums)
    {
        int i = 0, j = 0, n = nums.size();
        int deletion = 0;
        int maxLen = 0;
        while (j < n)
        {
            if (nums[j] == 0)
            {
                deletion++;
            }
            while (deletion > 1)
            {
                if (nums[i] == 0)
                {
                    deletion--;
                }
                i++;
            }
            maxLen = max(maxLen, j - i);
            j++;
        }
        return maxLen;
    }
};