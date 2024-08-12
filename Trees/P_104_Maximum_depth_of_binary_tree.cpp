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
    int maxDepth(TreeNode* root) {
        if(root==NULL){
            return 0;
        }
        queue<TreeNode*>qe;
        qe.push(root);
        int level=0;
        while(!qe.empty()){
            int n=qe.size();
            level++;
            while(n--){
                auto it=qe.front();
                qe.pop();
                if(it->left!=NULL){
                    qe.push(it->left);
                }
                if(it->right!=NULL){
                    qe.push(it->right);
                }
            }
        }
        return level;
    }
};