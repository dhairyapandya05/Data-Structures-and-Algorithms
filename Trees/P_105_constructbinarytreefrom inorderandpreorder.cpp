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
    TreeNode* solution(vector<int>& preorder, vector<int>& inorder, int& idx,
                       int start, int end) {

        if (start > end) {
            return NULL;
        }
        int element = preorder[idx];
        int i = start;
        TreeNode* root = new TreeNode(element);
        idx++;
        for (; i < preorder.size(); i++) {
            if (element == inorder[i]) {
                break;
            }
        }
        root->left = solution(preorder, inorder, idx, start, i - 1);
        root->right = solution(preorder, inorder, idx, i + 1, end);
        return root;
    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int idx = 0;
        int start = 0;
        int end = preorder.size() - 1;
        TreeNode* result = solution(preorder, inorder, idx, start, end);
        return result;
    }
};