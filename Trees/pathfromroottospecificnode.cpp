class Solution
{
    public:
    void solve(Node* root,int sum,vector<vector<int>>& result,vector<int> path){
        if(root==NULL){
            return;
        }
        if(sum==0){
            result.push_back(path);
        }
        sum-=root->key;
        path.push_back(root->key);
        if(!root->left){
            solve(root->left,sum,result,path);
        }
        if(!root->right){
            solve(root->right,sum,result,path);
        }
        
    }
    vector<vector<int>> printPaths(Node *root, int sum)
    {
        //code here
        vector<vector<int>> result;
        vector<int> path;
        solve(root,sum,result,path);
        return result;
    }
};
// https://www.geeksforgeeks.org/problems/paths-from-root-with-a-specified-sum/1