/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    bool solve(TreeNode* rootl,TreeNode* rootr){
        if(rootl==NULL and rootr==NULL){
            return true;
        }
        if(rootl==NULL or rootr==NULL){
            return false;
        }
        if(rootl->val!=rootr->val){
            return false;
        }
        bool rightans=solve(rootl->left,rootr->right);
        bool leftans=solve(rootl->right,rootr->left);
        return rightans and leftans;
    }
    bool isSymmetric(TreeNode* root) {
        bool ans=solve(root->left,root->right);
        return ans;
    }
};
// https://leetcode.com/problems/symmetric-tree/