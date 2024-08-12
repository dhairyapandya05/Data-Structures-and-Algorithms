class Solution{
    public:
    bool isLeaf(Node* root){
        return root->left==NULL and root->right==NULL;
    }
    int solve(Node* root){
        if(isLeaf(root)){
            return root->data;
        }
        int leftsum=0;
        if(root->left!=NULL){
            leftsum=solve(root->left);
            if(leftsum==0){
                return 0;
            }
        }
        int rightsum=0;
        if(root->right!=NULL){
            rightsum=solve(root->right);
            if(rightsum==0){
                return 0;
            }
        }
        if(rightsum+leftsum==root->data){
            return root->data;
        }
        else{
            return 0;
        }
    }
    //Function to check whether all nodes of a tree have the value 
    //equal to the sum of their child nodes.
    int isSumProperty(Node *root)
    {
     // Add your code here
     int ans=solve(root);
     if(ans==root->data){
         return 1;
     }
     return 0;
    }
};