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
// https://leetcode.com/problems/count-nodes-equal-to-average-of-subtree/description/
class Solution {
public:
    int count = 0;
    pair<int, int> subtreesum(TreeNode* root) {
        if (root == NULL) {
            return {0, 0};
        }
        pair<int, int> ans; // sum numberofnodes
        pair<int, int> ansl;
        pair<int, int> ansr;
        if (root->left != NULL) {
            ansl = subtreesum(root->left);
        }
        if (root->right != NULL) {
            ansr = subtreesum(root->right);
        }
        ans.first = ansl.first + ansr.first + root->val;
        ans.second = ansl.second + ansr.second + 1;
        if (ans.first / ans.second == root->val) {
            count++;
        }
        return ans;
    }
    int averageOfSubtree(TreeNode* root) {
        pair<int, int> ans = subtreesum(root);
        return count;
    }
};