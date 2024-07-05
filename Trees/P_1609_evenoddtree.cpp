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
    bool isEvenOddTree(TreeNode* root) {
        int level = 0;
        queue<TreeNode*> q;
        q.push(root);
        int cmp;
        while (!q.empty()) {
            int n = q.size();
            cmp = (level % 2 == 0) ? INT_MIN : INT_MAX;
            while (n--) {
                TreeNode* temp = q.front();
                q.pop();
                if(level%2==0){
                    if(temp->val%2==0 or cmp >=temp->val){
                        return false;
                    }
                }
                if(level%2==1){
                    if(temp->val%2==1 or cmp<=temp->val){
                        return false;
                    }
                }
                cmp=temp->val;
                if(temp->left!=NULL){
                    q.push(temp->left);
                }
                if(temp->right!=NULL){
                    q.push(temp->right);
                }
            }
            level++;
        }
        return true;
    }
};
// https://leetcode.com/problems/even-odd-tree/