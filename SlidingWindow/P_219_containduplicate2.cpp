class Solution
{
public:
    bool containsNearbyDuplicate(vector<int> &nums, int k)
    {
        int i = 0, j = 0;
        set<int> s;
        int n = nums.size();
        while (j < n)
        {
            if (abs(i - j) > k)
            {
                // we will need to shrink our window size form i
                s.erase(nums[i]);
                i++;
            }
            if (s.find(nums[j]) == s.end())
            {
                s.insert(nums[j]);
            }
            else
            {
                return true;
            }

            j++;
        }
        return false;
    }
};

// Alter approach
bool containsNearbyDuplicate(vector<int> &nums, int k)
{
    // sliding window of size k
    unordered_set<int> currentNums;
    for (auto it = nums.begin(); it != nums.end(); ++it)
    {
        // check if the num is in the sliding window
        if (currentNums.count(*it))
            return true;
        // insert to update window
        currentNums.insert(*it);
        // decrement left-side of window if it is greater than k
        if ((it - nums.begin()) >= k)
            currentNums.erase(*(it - k));
    }
    return false;
}