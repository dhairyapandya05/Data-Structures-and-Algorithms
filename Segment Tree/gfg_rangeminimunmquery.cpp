// Link:https://www.geeksforgeeks.org/problems/range-minimum-query/1
void buildTree(int i, int s, int e, int nums[], int tree[])
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
int *constructST(int arr[], int n)
{
    // Your code here
    int *tree = new int[4 * n + 1]; // Allocate dynamically
    buildTree(1, 0, n - 1, arr, tree);
    return tree;
}
int query(int i, int s, int e, int qS, int qE, int tree[])
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

/* The functions returns the
 min element in the range
 from a and b */
int RMQ(int st[], int n, int a, int b)
{
    // Your code here
    return query(1, 0, n - 1, a, b, st);
}