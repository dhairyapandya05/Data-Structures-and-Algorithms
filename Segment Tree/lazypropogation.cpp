void updateRange(int qS, int qE, int i, int left, int right, int val, vector<int> &tree, vector<int> &lazy)
{
    if (lazy[i] != 0)
    {
        tree[i] += (right - left + 1) * lazy[i];
        if (left != right)
        {                               // it is not a leaf node
            lazy[2 * i] += lazy[i];     // it is a leaf node
            lazy[2 * i + 1] += lazy[i]; // it's right subchild it could be useful for future queries
        }
        // reseting the lazy segment
        lazy[i] = 0;
    }

    // out of range
    if (qS > right || qE < left || left > right)
        return;

    // current segment is fully inside the query range
    if (qS <= left && qE >= right)
    {
        tree[i] += (right - left + 1) * val;
        if (left != right) // it is not a leaf node
        {
            lazy[2 * i] += val;     // it is a leaf node
            lazy[2 * i + 1] += val; // it's right subchild it could be useful for future queries
        }
        return; // mae niichae nahi gaya it is most important
    }
    int mid = (left + right) / 2;
    // query is partially overlapping with current segment
    updateRange(qS, qE, 2 * i, left, mid, val, tree, lazy);
    updateRange(qS, qE, 2 * i + 1, mid + 1, right, val, tree, lazy);
    // merging the result
    tree[i] = tree[2 * i] + tree[2 * i + 1];
}

// Important:  the size of the lazy will be [4*n+1]
// Time complexity Olog(N)