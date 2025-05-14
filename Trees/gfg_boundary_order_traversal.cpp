class Solution {
public:
    bool LeafNode(Node *root) {
        if (root->left == NULL and root->right == NULL) {
            return true;
        }
        return false;
    }
    vector<int> leftviewans;
    void leftViewTraversal(Node *root) {
        if (root == NULL or LeafNode(root)) {
            return;
        }
        leftviewans.push_back(root->data);
        if (root->left != NULL) {
            leftViewTraversal(root->left);
        } else {
            leftViewTraversal(root->right);
        }
    }
    vector<int> rightviewans;
    void rightViewTraversal(Node *root) {
        if (root == NULL or LeafNode(root)) {
            return;
        }
        rightviewans.push_back(root->data);
        if (root->right != NULL) {
            rightViewTraversal(root->right);
        } else {
            rightViewTraversal(root->left);
        }
    }
    vector<int> leafnodes;
    void leafNodesTraversal(Node *root) {
        if (root->left != NULL) {
            leafNodesTraversal(root->left);
        }
        if (LeafNode(root)) {
            leafnodes.push_back(root->data);
        }
        if (root->right != NULL) {
            leafNodesTraversal(root->right);
        }
    }

    vector<int> boundaryTraversal(Node *root) {
        // code here
        leftViewTraversal(root->left);
        rightViewTraversal(root->right);
        leafNodesTraversal(root);
        vector<int> finalans;
        if (!LeafNode(root)) {
            finalans.push_back(root->data);
        }
        finalans.insert(finalans.end(), leftviewans.begin(), leftviewans.end());
        finalans.insert(finalans.end(), leafnodes.begin(), leafnodes.end());
        reverse(rightviewans.begin(), rightviewans.end());
        finalans.insert(finalans.end(), rightviewans.begin(), rightviewans.end());
        return finalans;
    }
};

Link : https: // www.geeksforgeeks.org/problems/boundary-traversal-of-binary-tree/1