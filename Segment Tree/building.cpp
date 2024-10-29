// Important: sum in a range can be done by prefix sum itself but there may arise some instances where we have to find ot the max-element in a range then in that kind of problems we will have to use segment trees

#include <bits/stdc++.h>
using namespace std;
void buildTree(int i, int s, int e, vector<int> &nums, vector<int> &tree)
{
    if (s == e)
    {
        tree[i] = nums[s];
        return;
    }
    int mid = (s + e) / 2;
    buildTree(2 * i, s, mid, nums, tree);
    buildTree(2 * i + 1, mid + 1, e, nums, tree);
    int left = tree[2 * i];
    int right = tree[2 * i + 1];
    tree[i] = min(left, right);
}

int query(int i, int s, int e, int qS, int qE, vector<int> &tree)
{
    // no overlap
    if (qS > e or qE < s)
    {
        return INT_MAX;
    }
    // complete overlap
    if (s >= qS and e <= qE)
    {
        return tree[i];
    }
    // partial overlap
    int mid = (s + e) / 2;
    int left = query(2 * i, s, mid, qS, qE, tree);
    int right = query(2 * i + 1, mid + 1, e, qS, qE, tree);
    return min(left, right);
}

void updateNode(int i, int qS, int qE, vector<int> &tree, int &value)
{
    // reached the leaf node
    if (qS == qE)
    {
        tree[i] = value;
        return;
    }
    // partial overlap
    int mid = (qS + qE) / 2;

    if (i <= mid)
        updateNode(2 * i, qS, mid, tree, value);
    else
        updateNode(2 * i + 1, mid + 1, qE, tree, value);

    tree[i] = min(tree[2 * i], tree[2 * i + 1]);
}

void rangeUpdate(int i, int s, int e, int rS, int rE, vector<int> &tree, int inc)
{
    // no overlap
    if (rS > e || rE < s)
        return;

    // reached the leaf node
    if (s == e)
    {
        tree[i] += inc;
        return;
    }

    // partial overlap
    int mid = (s + e) / 2;
    rangeUpdate(2 * i, s, mid, rS, rE, tree, inc);
    rangeUpdate(2 * i + 1, mid + 1, e, rS, rE, tree, inc);
    tree[i] = min(tree[2 * i], tree[2 * i + 1]);
}
// Time complexity O(Qlog(N))