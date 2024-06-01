/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(root==NULL){
            return NULL;
        }
        if(p==root or q==root){
            return root;
        }
        root->left=lowestCommonAncestor(root->left,p,q);
        root->right=lowestCommonAncestor(root->right,p,q);
        if(root->left!=NULL and root->right!=NULL){
            return root;
        }
        if(root->left!=NULL){
            return root->left;
        }
        return root->right;
    }
};