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
    void solve(TreeNode* root, int& val, int& depth, int currentdepth) {
        if (root == NULL) {
            return ;
        }
        ++currentdepth;
        if (currentdepth +1 == depth) {
            TreeNode* templeft = root->left;
            TreeNode* tempright = root->right;
            TreeNode* leftNew = new TreeNode(val);
            TreeNode* rightNew = new TreeNode(val);
            root->left = leftNew;
            root->right = rightNew;
            leftNew->left = templeft;
            rightNew->right = tempright;
            // return root;
        } else {
            solve(root->left, val, depth, currentdepth);
            solve(root->right, val, depth, currentdepth);
        }
    }
    TreeNode* addOneRow(TreeNode* root, int val, int depth) {
        int currdepth = 0;
        if (depth == 1) {
            TreeNode* leftNew = new TreeNode(val);
            leftNew->left = root;
            return leftNew;
        } else {
            solve(root, val, depth, currdepth);
            return root;
        }
    }
};

//DHAIRYA PANDY's solution
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
    TreeNode* addOneRow(TreeNode* root, int val, int depth) {
        if(depth==1){
            TreeNode* newNode= new TreeNode(val);
            newNode->left=root;
            return newNode;
        }
        queue<TreeNode*> q;
        q.push(root);
        while (!q.empty()) {
            int n = q.size();
            depth--;

            while (n--) {
                TreeNode* temp = q.front();
                if (depth == 1) {
                    TreeNode* temproot = q.front();
                    q.pop();
                    TreeNode* tempright = temproot->right;
                    TreeNode* templeft = temproot->left;
                    TreeNode* newright = new TreeNode(val);
                    TreeNode* newleft = new TreeNode(val);
                    temproot->left = newleft;
                    temproot->right = newright;
                    newleft->left = templeft;
                    newright->right = tempright;
                    // break;
                    continue;
                }
                q.pop();

                if (temp->left != NULL) {
                    q.push(temp->left);
                }
                if (temp->right != NULL) {
                    q.push(temp->right);
                }
            }
        }
        return root;
    }
};