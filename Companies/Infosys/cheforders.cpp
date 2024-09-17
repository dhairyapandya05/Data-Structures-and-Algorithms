#include <bits/stdc++.h>
// typedef pair<int, int> p;
using namespace std;

struct customcmp
{
    bool operator()(vector<int> &p1, vector<int> &p2)
    {
        if (p1[0] == p2[0])
        {
            return p1[1] > p2[1];
        }
        return p1[0] > p2[0];
    }
};
auto cmp = [&](vector<int> &p1, vector<int> &p2)
{
    if (p1[1] == p2[1])
    {
        return p1[0] < p2[0];
    }
    return p1[1] < p2[1];
};
vector<int> solve(vector<int> time, vector<int> processing, int &c, int &k)
{
    vector<vector<int>> dish;
    for (int i = 0; i < processing.size(); i++)
    {
        dish.push_back({time[i], processing[i],i});
    }
    vector<int> finalans(dish.size());
    priority_queue<vector<int>, vector<vector<int>>, customcmp> pq(dish.begin(), dish.end());
    int t=0;
    while (!pq.empty())
    {
        auto it = pq.top();
        pq.pop();
        if(t<it[0]){
            t=it[0];
        }
        vector<vector<int>> arr;
        arr.push_back(it);
        while (!pq.empty() and t >= pq.top()[0])
        {
            arr.push_back(pq.top());
            pq.pop();
        }
        sort(arr.begin(), arr.end(), cmp);
        auto itt = arr[0];
        int i = 1;
        while (i < arr.size())
        {
            pq.push(arr[i]);
            i++;
        }
        arr.clear();
        int waitingtime = 0;
        int processingtime=itt[1];
        if (t > itt[0])
        {
            waitingtime = t - itt[0];
        }
        int profit = (processingtime * c) - (waitingtime * k);
        int idx=itt[2];
        finalans[idx]=max(profit,0);
        t += processingtime;
    }
    return finalans;

}
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int numberoforder, c, k;
        cin >> numberoforder;
        cin >> c;
        cin >> k;
        vector<int> processing;
        vector<int> time;
        while (numberoforder--)
        {
            int processing_t, ti;
            cin >> ti;
            time.push_back(ti);
            cin >> processing_t;
            processing.push_back(processing_t);
        }
        vector<int> ans = solve(time, processing, c, k);
        for (auto it : ans)
        {
            cout << it << " ";
        }
        cout << endl;
    }

    return 0;
}
// testcase
// 1
// 3 10 16
// 1 2
// 2 3
// 3 1