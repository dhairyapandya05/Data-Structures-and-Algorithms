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
    TreeNode* solve(vector<int>& preorder, vector<int>& inorder, int& idx, int start,int end) {
        if (start > end) {
            return NULL;
        }
        int element = preorder[idx];
        int i = start;
        for (; i <= end; i++) {
            if (inorder[i] == element)
                break;
        }
        TreeNode* node=new TreeNode(element);
        idx++;
        node->left = solve(preorder, inorder,idx, start, i - 1);
        node->right = solve(preorder, inorder, idx, i + 1, end);
        return node;
    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int idx = 0;
        int start = 0;
        int end = preorder.size();
        TreeNode* root = solve(preorder, inorder, idx, start, end-1);
        return root;
    }
};