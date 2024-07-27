// https://www.geeksforgeeks.org/problems/implementing-ceil-in-bst/1
int findCeil(Node* root, int input) {
    int ceilno =-1;
    while(root){
        if(root->data==input){
            ceilno=root->data;
            return ceilno;
        }
        else if(root->data>input){
            ceilno=root->data;
            root=root->left;
        }
        else{
            root=root->right;
        }
    }
    return ceilno;

    // Your code here
}