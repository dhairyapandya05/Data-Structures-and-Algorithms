class Solution
{
    public:
    void findPreSuc(Node* root, Node*& pre, Node*& suc, int key)
    {
        Node* originalroot=root;
        while(root!=NULL){
            if(key>=root->key){
                // pre=root;
                root=root->right;
            }
            else{
                suc=root;
                root=root->left;
            }
        }
        while(originalroot!=NULL){
            if(originalroot->key<key){
                pre=originalroot;
                originalroot=originalroot->right; 
                
            }
            else{
                    originalroot=originalroot->left;
            }
        }
    }
};
// link:https://www.geeksforgeeks.org/problems/predecessor-and-successor/1