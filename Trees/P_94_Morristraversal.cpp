vector<int> preorder(Node *root) {
    // Your code here
    Node *curr = root;
    vector<int> preorder;
    if (root == NULL) {
        return preorder;
    }
    while (curr != NULL) {
        if (curr->left == NULL) {
            preorder.push_back(curr->data);
            curr = curr->right;
        } else {
            Node *prev = curr->left;
            while (prev->right != NULL and prev->right != curr) {
                prev = prev->right;
            }
            if (prev->right == NULL) { // make a link to the curr node
                prev->right = curr;
                preorder.push_back(curr->data);
                curr = curr->left;
            } else {
                prev->right = NULL;
                curr = curr->right;
            }
        }
    }
    return preorder;
}

// Morris inorder traversal;
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
 * right(right) {}
 * };
 */
class Solution {
public:
    vector<int> inorderTraversal(TreeNode *root) {
        TreeNode *curr = root;
        vector<int> inorder;
        if (root == NULL) {
            return inorder;
        }
        while (curr != NULL) {
            if (curr->left == NULL) {
                inorder.push_back(curr->val);
                curr = curr->right;
            } else {
                TreeNode *prev = curr->left;
                while (prev->right != NULL and prev->right != curr) {
                    prev = prev->right;
                }
                if (prev->right == NULL) {
                    prev->right = curr;
                    curr = curr->left;
                } else {
                    prev->right = NULL;
                    inorder.push_back(curr->val);
                    curr = curr->right;
                }
            }
        }
        return inorder;
    }
};

// Speciality of Morris traversal it doesnot include any special space
// TC:O(N)
// SC:O(1)