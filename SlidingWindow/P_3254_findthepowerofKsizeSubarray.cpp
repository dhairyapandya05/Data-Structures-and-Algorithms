class Solution
{
public:
    vector<int> resultsArray(vector<int> &nums, int k)
    {
        int i = 0, j = 0;
        deque<int> de;
        int n = nums.size();
        vector<int> ans(n - k + 1, -1);
        while (j < n)
        {
            if (j != 0 and nums[j - 1] + 1 != nums[j])
            {
                de.push_back(j);
            }
            if (j - i + 1 == k)
            {

                if (de.front() == i)
                {
                    de.pop_front();
                }
                if (de.empty() == true)
                {
                    ans[i] = nums[j];
                }
                i++;
                /*
Why This Order?

First Condition (de.front() == i):
Ensures that the deque is cleaned up before checking whether it is empty.
If the front of the deque corresponds to the starting index of the current
window (i), it is popped because it is no longer relevant after sliding the
window. Second Condition (de.empty() == true): This checks whether the current
window has no breaking points after any necessary clean-up. Only then is the
result updated with nums[j].
                */
            }
            j++;
        }
        return ans;
    }
};