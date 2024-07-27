class Solution {
  public:
    // Function to check whether a Binary Tree is BST or not.
    bool solve(Node* root, int minval, int maxval) {
        if (!root) {
            return true;
        }
        if (root->data <= minval or root->data >= maxval) {
            return false;
        }
        bool a = solve(root->left, minval, root->data);
        bool b = solve(root->right, root->data, maxval);
        return a and b;
    }
    bool isBST(Node* root) {
        // Your code here
        return solve(root, INT_MIN, INT_MAX);
    }
};
// link:https://www.geeksforgeeks.org/problems/check-for-bst/1