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
// The tree is a complete binary tree
class Solution {
public:
    int leftHeight(TreeNode* root, int& lh) {
        if (root == NULL) {
            return lh;
        }
        lh++;
        return leftHeight(root->left, lh);
    }

    int rightHeight(TreeNode* root, int& rh) {
        if (root == NULL) {
            return rh;
        }
        rh++;
        return rightHeight(root->right, rh);
    }
    int countNodes(TreeNode* root) {
        if (root == NULL) {
            return 0;
        }
        int lh = 0;
        int rh = 0;
        int leftheight = leftHeight(root, lh);
        int rightheight = rightHeight(root, rh);
        if (leftheight == rightheight) {
            int nodecount = pow(2, rightheight) - 1;
            cout<<nodecount;
            return nodecount;
        } else { 
            int leftct = countNodes(root->left);
            int rightct = countNodes(root->right);
            return leftct + rightct + 1;
        }
    }
};