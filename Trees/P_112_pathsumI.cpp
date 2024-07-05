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
    bool solve(TreeNode* root, int targetSum){
        if(root==NULL){
            return NULL;
        }
        targetSum-=root->val;
        cout<<targetSum;
        if(root->left==NULL and root->right==NULL){
            if(targetSum==0){
                return true;
            }
        }
        else{
            bool leftans=solve(root->left,targetSum);
            bool rightans=solve(root->right,targetSum);
            return leftans or rightans;
        }
        return false;
    }

    bool hasPathSum(TreeNode* root, int targetSum) {
        bool result=solve(root,targetSum);
        return result;
    }
};