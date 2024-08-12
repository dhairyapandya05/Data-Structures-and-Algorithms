class Solution {
  public:
  vector<vector<int>> ans;
  vector<int> temp;
  void solve(Node* root){
      if(root==NULL){
          return;
      }
      temp.push_back(root->data);
      if(root->left!=NULL){
          solve(root->left);
          temp.pop_back();//vvv important step
      }
      if(root->right!=NULL){
          solve(root->right);
          temp.pop_back();//vvv important step
      }
      if(root->left==NULL and root->right==NULL){
          ans.push_back(temp);
      }
  }
    vector<vector<int>> Paths(Node* root) {
        solve(root);
        return ans;
    }
};