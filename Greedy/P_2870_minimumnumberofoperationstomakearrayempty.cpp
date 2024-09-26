int minOperations(vector<int> &nums)
{
    unordered_map<int, int> hash;
    for (int i = 0; i < nums.size(); i++)
    {
        hash[nums[i]]++;
    }
    int ans = 0;
    for (auto i : hash)
    {
        if (i.second == 1)
        {
            return -1;
        }
        ans += ceil(i.second / 3.0);
    }
    return ans;
}
}
;