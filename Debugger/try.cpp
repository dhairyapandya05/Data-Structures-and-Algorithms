#include <bits/stdc++.h>
using namespace std;

int maximumScore(vector<int> &nums, int k)
{
    int n = nums.size();
    int l = k;
    int r = k;
    int ans = nums[k];
    int mini = nums[k];
    int i=0;
    while (l - 1 >= 0 or r + 1 <= n - 1)
    {
        i++;
        if (r==n-1 or (l - 1 >= 0 and nums[l - 1] > nums[r + 1]))
        {
            l--;
            mini = min(nums[l], mini);
            ans = max(ans, mini * (r - l + 1));
        }
        else if (l==0 or (r + 1 <= n - 1 and nums[l - 1] <= nums[r + 1]))
        {
            r++;
            mini = min(nums[r], mini);
            ans = max(ans, mini * (r - l + 1));
        }
    }
    return ans;
}
int main()
{
    vector<int> nums={5,5,4,5,4,1,1,1};
    int k = 0;
    int ans=maximumScore(nums,k);
    cout<<endl<<"Answer: "<<ans;
    return 0;
}