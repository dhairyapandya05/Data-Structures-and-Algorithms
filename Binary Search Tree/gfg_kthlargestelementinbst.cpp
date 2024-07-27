class Solution
{
    public:
    int solve(Node* root, int& k) {
        if (!root) {
            return -1;
        }
        //R
        int right=solve(root->right,k);
        if(right!=-1){
            return right;
        }
        //N
        k--;
        if(k==0){
            return root->data;
        }
        //L
        return solve(root->left,k);
    }
    int kthLargest(Node *root, int k)
    {
        //Your code here
        int ans=solve(root,k);
        return ans;
    }
};
// link:https://www.geeksforgeeks.org/problems/kth-largest-element-in-bst/1