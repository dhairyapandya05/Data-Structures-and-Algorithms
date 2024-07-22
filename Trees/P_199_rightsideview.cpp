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
    void solve(int level, vector<int>& result, TreeNode* root) {
        if (root == NULL) {
            return;
        }
        if (result.size() < level) {
            result.push_back(root->val);
        }
        solve(level + 1, result, root->right);// here order is important we are talking right first and then  left
        solve(level + 1, result, root->left);
    }
    vector<int> rightSideView(TreeNode* root) {
        vector<int> result;
        solve(1, result, root);
        return result;
        // queue<TreeNode*> q;
        // q.push(root);
        // TreeNode* ptr = NULL;
        // vector<int> result;
        // if(root==NULL){
        //     return result;
        // }
        // int n;
        // while (!q.empty()) {
        //     n = q.size();
        //     while (n--) {
        //         ptr = q.front();
        //         q.pop();
        //         if (ptr->left != NULL) {
        //             q.push(ptr->left);
        //         }
        //         if (ptr->right != NULL) {
        //             q.push(ptr->right);
        //         }
        //     }
        //     result.push_back(ptr->val);
        // }
        // return result;
    }
};