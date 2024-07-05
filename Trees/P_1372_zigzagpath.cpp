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
// link:https://leetcode.com/problems/longest-zigzag-path-in-a-binary-tree/description/
class Solution {
public:
    int maxpath = 0;
    void solve(TreeNode* root, bool goleft, int steps) {
        // yaha par steps pass by value hai kyoki har ek node kae lilae steps allag alaag hogae ... and goleft ka value bhi depend karaega.
        if (root == NULL) {
            return;
        }
        maxpath = max(maxpath, steps);
        if (goleft == true) {
            solve(root->left, false, ++steps);
            solve(root->right, true, 1);
        } else {
            solve(root->left, false, 1);
            solve(root->right, true, ++steps);
        }
    }
    int longestZigZag(TreeNode* root) {
        bool goleft = false;
        solve(root, goleft, 0);
        solve(root, !goleft, 0);
        return maxpath;
    }
};