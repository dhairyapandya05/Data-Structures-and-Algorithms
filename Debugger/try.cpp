#include <bits/stdc++.h>
using namespace std;

int longestSquareStreak(vector<int> &nums)
{
    set<int> st(nums.begin(), nums.end());
    unordered_map<int, int> mp;
    int maxans = 0;
    int n = nums.size();
    vector<int> visited(n, 0); // unvisited
    int i = 0;
    for (auto it : st)
    {
        if (visited[i] == 1)
        {
            continue;
        }
        cout << "Value of i: " << i << endl;
        visited[i] = 1; // marking it as visited
        int curr = it;
        int cnt = 1;
        curr *= it;
        while (st.count(curr) != 0)
        {
            cout << "Value of changed curr: " << curr << endl;
            cnt++;
            auto it = st.find(curr);
            int dist = distance(st.begin(), it);
            visited[dist] = 1;
            curr *= curr;
        }
        mp[it] = cnt;
        cout << "it: " << it << " and " << "cnt: " << cnt << endl;
        maxans = max(maxans, cnt);
        i++;
    }
    return maxans;
}

int main()
{
    vector<int> nums = {2, 4};
    int ans = longestSquareStreak(nums);
    cout << endl
         << "Final Answer: " << ans << endl;

    return 0;
}
