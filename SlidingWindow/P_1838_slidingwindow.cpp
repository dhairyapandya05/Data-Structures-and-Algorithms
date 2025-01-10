class Solution
{
public:
    int binarySearch(int targetIdx, int k, vector<int> &nums, vector<long> &prefix)
    {
        int s = 0;
        int e = targetIdx;
        int target = nums[targetIdx];
        int result = targetIdx;
        while (s <= e)
        {
            int mid = s + (e - s) / 2;

            long count = (targetIdx - mid + 1);
            long windowSum = (count * target);
            long currSum = prefix[targetIdx] - prefix[mid] + nums[mid];
            int ops = windowSum - currSum;
            if (ops > k)
            {
                s = mid + 1;
            }
            else
            {
                result = mid;
                e = mid - 1;
            }
        }
        return targetIdx - result + 1;
    }
    int maxFrequency(vector<int> &nums, int k)
    {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        vector<long> prefix(n);
        prefix[0] = nums[0];
        for (int i = 1; i < n; i++)
        {
            prefix[i] = prefix[i - 1] + nums[i];
        }
        int result = 0;
        for (int i = 0; i < n; i++)
        {
            result = max(result, binarySearch(i, k, nums, prefix));
        }
        return result;
    }
};

// Method 2
class Solution
{
public:
    int maxFrequency(vector<int> &nums, int k)
    {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        int result = 0;
        int i = 0, j = 0;
        long currSum = 0;
        while (j < n)
        {
            currSum += nums[j];
            long target = nums[j];
            while ((j - i + 1) * target - currSum > k)
            {
                currSum -= nums[i];
                i++;
            }
            result = max(result, j - i + 1);
            j++;
        }
        return result;
    }
};

// Improved method 2
class Solution
{
public:
    int maxFrequency(vector<int> &nums, int k)
    {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        int result = 0;
        int i = 0, j = 0;
        long currSum = 0;
        while (j < n)
        {
            currSum += nums[j];
            long target = nums[j];
            if ((j - i + 1) * target - currSum > k) // Important: changing while keyword to if will work since it will reduce our window size
            {
                currSum -= nums[i];
                i++;
            }
            result = max(result, j - i + 1);
            j++;
        }
        return result;
    }
};