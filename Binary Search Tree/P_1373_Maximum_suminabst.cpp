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
class NodeValue {
public:
    int maxValue;
    int minValue;
    int numberOfNodes;
    int sum;
    NodeValue(int maxValue, int minValue, int numberOfNodes,int sum) {
        this->maxValue = maxValue;
        this->minValue = minValue;
        this->numberOfNodes = numberOfNodes;
        this->sum=sum;
    }
};
class Solution {
public:
    NodeValue solve(TreeNode* root,int& ans) {
        if (!root) {
            return NodeValue(INT_MIN, INT_MAX, 0,0);
        }
        auto left = solve(root->left,ans);
        auto right = solve(root->right,ans);
        if (left.maxValue < root->val and right.minValue > root->val) {
            ans=max(ans,left.sum+right.sum+root->val);
            return NodeValue(max(right.maxValue, root->val),
                             min(left.minValue, root->val),
                             left.numberOfNodes + right.numberOfNodes + 1,left.sum+right.sum+root->val);
        }
        return NodeValue(INT_MAX, INT_MIN,
                         max(left.numberOfNodes, right.numberOfNodes),max(left.sum,right.sum));
    }
    int maxSumBST(TreeNode* root) {
        int ans=0;
        auto finalans=solve(root,ans);
        return ans;
    }
};