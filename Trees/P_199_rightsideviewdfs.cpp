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
    void solution (TreeNode* root, int level, vector<int>& result) {
        if(root==NULL){
            return;
        }
        if(result.size() < level){
            result.push_back(root->val);
        }
        solution(root->right,level+1,result);
        solution(root->left,level+1,result);
    }
    vector<int> rightSideView(TreeNode* root) {
        int level = 1;
        vector<int> result;
        solution(root, level, result);
        return result;
    }
};