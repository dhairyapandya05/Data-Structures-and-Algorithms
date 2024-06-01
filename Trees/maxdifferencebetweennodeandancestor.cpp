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
    void solve(TreeNode* root,int maxVal,int minVal,int& diff){
        if(root==NULL){
            return;
        }
        maxVal=max(maxVal,root->val);
        minVal=min(minVal,root->val);

        diff=max(abs(maxVal-minVal),diff);

        solve(root->left,maxVal,minVal,diff);
        solve(root->right,maxVal,minVal,diff);
    }
    int maxAncestorDiff(TreeNode* root) {
        int maxdiff=0;
        int maxVal=root->val;
        int minVal=root->val;
        solve(root,maxVal,minVal,maxdiff);
        // maxdiff=maxVal-minVal;
        return maxdiff;
    }
};

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
    void solve(TreeNode* root,int maxValue,int minValue,int& maxdifference){
        if(root==NULL){
            return;
        }
        maxValue=max(maxValue,root->val);
        minValue=min(minValue,root->val);
        maxdifference=max(abs(maxValue-minValue),maxdifference);
        solve(root->left,maxValue,minValue,maxdifference);
        solve(root->right,maxValue,minValue,maxdifference);
    }
    int maxAncestorDiff(TreeNode* root) {
        int maxValue=root->val;
        int minValue=root->val;
        int maxdifference=abs(maxValue-minValue);
        solve(root,maxValue,minValue,maxdifference);
        return maxdifference;
    }
};