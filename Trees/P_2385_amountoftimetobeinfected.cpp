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
    unordered_map<int, vector<int>> graph;

    int amountOfTime(TreeNode* root, int start) {
        constructGraph(root);

        queue<int> q;
        q.push(start);

        unordered_set<int> visited;

        int minutesPassed = -1;

        while (!q.empty()) {
            ++minutesPassed;
            for (int levelSize = q.size(); levelSize > 0; --levelSize) {
                int currentNode = q.front();
                q.pop();
                visited.insert(currentNode);
                for (int adjacentNode : graph[currentNode]) {
                    if (!visited.count(adjacentNode)) {
                        q.push(adjacentNode);
                    }
                }
            }
        }

        return minutesPassed;
    }

    void constructGraph(TreeNode* root) {
        if (!root) return;

        if (root->left) {
            graph[root->val].push_back(root->left->val);
            graph[root->left->val].push_back(root->val);
        }

        if (root->right) {
            graph[root->val].push_back(root->right->val);
            graph[root->right->val].push_back(root->val);
        }

        constructGraph(root->left);
        constructGraph(root->right);
    }
};

// My method
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
    map<TreeNode*, TreeNode*> childparent;
    TreeNode* startNode;
    void inorder(TreeNode* root,int& start) {
        if (root == NULL) {
            return;
        }
        if(start==root->val){
            startNode=root;
        }
        if (root->left != NULL) {
            childparent[root->left] = root;
            inorder(root->left,start);
        }
        if (root->right != NULL) {
            childparent[root->right] = root;
            inorder(root->right,start);
        }
    }
    int amountOfTime(TreeNode* root, int& start) { 
        unordered_set<TreeNode*> visited;
        inorder(root,start);
        int time=-1;
        queue<TreeNode*> q;
        q.push(startNode);
        visited.insert(startNode);
        while(!q.empty()){
            int n=q.size();
            ++time;
            while(n--){
                TreeNode* temp=q.front();
                q.pop();
                if(temp->left!=NULL and visited.find(temp->left)==visited.end()){
                    q.push(temp->left);
                    visited.insert(temp->left);
                }
                if(temp->right!=NULL and visited.find(temp->right)==visited.end()){
                    q.push(temp->right);
                    visited.insert(temp->right);
                }
                if(childparent[temp]!=NULL and visited.find(childparent[temp])==visited.end()){
                    q.push(childparent[temp]);
                    visited.insert(childparent[temp]);
                }
            }
        }
    return time;
    }
};