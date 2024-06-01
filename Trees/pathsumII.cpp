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
    void solution(TreeNode* root, int targetSum, vector<vector<int>>& ans,
                  vector<int> path) {
        if (root == NULL) {
            return;
        }
        path.push_back(root->val);
        targetSum -= root->val;
        if (root->left == NULL and root->right == NULL and targetSum == 0) {
            ans.push_back(path);
        }
        solution(root->left, targetSum, ans, path);
        solution(root->right, targetSum, ans, path);
    }
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        vector<vector<int>> ans;
        vector<int> path;
        solution(root, targetSum, ans, path);
        return ans;
    }
};