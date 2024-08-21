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
    void cmp(TreeNode* root, int value) {
        TreeNode* temp = root;
        while (temp != NULL) {
            if (temp->val > value) {
                temp = temp->left;
            }
            if (temp->val < value) {
                temp = temp->right;
            }
        }
        TreeNode* node = new TreeNode(value);
        temp=node;
    }
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        TreeNode* root = new TreeNode(preorder[0]);

        for (int i = 1; i < preorder.size(); i++) {
            cmp(root, preorder[i]);
        }
    }
};