class Solution
{
public:
    void buildTree(int i, int s, int e, int nums[], vector<int> &tree)
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
        tree[i] = left + right;
    }
    int query(int i, int s, int e, int qS, int qE, vector<int> &tree)
    {
        // no overlap
        if (qS > e or qE < s)
        {
            return 0;
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
        return left + right;
    }
    vector<int> querySum(int n, int arr[], int q, int queries[])
    {
        // code here
        vector<int> ans;
        // int n=arr.size();
        vector<int> tree(4 * n + 1, -1);
        buildTree(1, 0, n - 1, arr, tree);
        for (int i = 0; i < q; i++)
        {
            int qS = queries[2 * i] - 1;
            int qE = queries[2 * i + 1] - 1;
            int temp = query(1, 0, n - 1, qS, qE, tree);
            ans.push_back(temp);
        }
        return ans;
    }
};