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
    vector<int>vec;
    void solve(TreeNode* root){
        if(root==NULL){
            return;
        }
        solve(root->left);
        vec.push_back(root->val);
        solve(root->right);
    }
    bool findTarget(TreeNode* root, int k) {
        solve(root);
        int l=0;
        int h=vec.size()-1;
        while(l<h){
            if(vec[l]+vec[h]>k){
                h--;
            }
            else if(vec[l]+vec[h]<k){
                l++;
            }
            else{
                return true;
            }
        }
        return false;
    }
};

// Method 2
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
class BSTIterator {
public:
    stack<TreeNode*> st;
    bool reverse = true;
    BSTIterator(TreeNode* root, bool isReverse) {
        reverse = isReverse;
        pushAll(root);
    }

    int next() {
        TreeNode* temp = st.top();
        st.pop();
        if (reverse == false) {
            pushAll(temp->right);

        } else {
            pushAll(temp->left);
        }
        return temp->val;
    }

    bool hasNext() { return !st.empty(); }
    void pushAll(TreeNode* root) {
        while (root != NULL) {
            st.push(root);
            if(reverse==false){
            root = root->left;

            }
            else{
                root=root->right;
            }
        }
    }
};
class Solution {
public:
    bool findTarget(TreeNode* root, int k) {
        BSTIterator l(root,false);
        BSTIterator r(root,true);
        int i=l.next();
        int j=r.next();
        while(i<j){
            if(i+j==k){
                return true;
            }
            else if(i+j>k){
                j=r.next();
            }
            else{
                i=l.next();
            }
        }
        return false;
    }
};