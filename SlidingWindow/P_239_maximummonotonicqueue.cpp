class Solution
{
public:
    vector<int> maxSlidingWindow(vector<int> &nums, int k)
    {
        vector<int> ans;
        int i = 0, n = nums.size();
        deque<int> de;
        for (; i < n; i++)
        {
            while (!de.empty() and de.front() < i - k + 1)
            {
                de.pop_front();
            }

            while (!de.empty() and nums[de.back()] <= nums[i])
            {
                de.pop_back();
            }

            de.push_back(i);
            if (i >= k - 1)
            {
                ans.push_back(nums[de.front()]);
            }
        }
        return ans;
    }
};