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
    TreeNode* solution(TreeNode* root, int target){
        if(root==NULL){
            return NULL;
        }
        root->left=solution(root->left,target);
        root->right=solution(root->right,target);
        if(root->val==target and root->left==NULL and root->right==NULL){
            return NULL;
        }
        else{
            return root;
        }
    }
    TreeNode* removeLeafNodes(TreeNode* root, int target) {
        TreeNode* ans=solution(root,target);
        return ans;
    }
};
// https://leetcode.com/problems/delete-leaves-with-a-given-value/