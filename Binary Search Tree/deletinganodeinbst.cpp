int minValue(Node* root) {
    Node* current = root;
    while (current->left != NULL) {
        current = current->left;
    }
    return current->data;
}
// Function to delete a node from BST.
Node *deleteNode(Node *root, int X) {
    // your code goes here
    if(!root){
        return NULL;
    }
    if(root->data<X){
        root->right=deleteNode(root->right,X);
    }
    else if(root->data>X){
        root->left=deleteNode(root->left,X);
    }
    else{
        if(root->left==NULL){
            return root->right;
        }
        else if(root->right==NULL){
            return root->left;
        }
        root->data=minValue(root->right);
        root->right=deleteNode(root->right,root->data);
    }
    return root;
}