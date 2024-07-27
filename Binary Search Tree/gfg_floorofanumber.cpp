// https://www.geeksforgeeks.org/problems/floor-in-bst/0
class Solution{

public:
    int floor(Node* root, int input) {
        // Code here
        int floorno =-1;
        while(root){
            if(root->data==input){
                floorno=root->data;
                return floorno;
            }
            else if(root->data>input){
                root=root->left;
            }
            else{
                floorno=root->data;
                root=root->right;
            }
        }
        return floorno;
    }
};