void inorder(Node *root, vector<int> &arr) {
    // If the current node is NULL
    // (base case for recursion), return
    if (root == nullptr) {
        return;
    }
    // Recursively traverse the left subtree
    inorder(root->left, arr);
    // Push the current node's
    // value into the vector
    arr.push_back(root->data);
    // Recursively traverse
    // the right subtree
    inorder(root->right, arr);
}

TC : O(N)
SC :O(log2N) average case and O(n) for the average case
In order preorder and postorder traversal all takes O(N) space complexity
