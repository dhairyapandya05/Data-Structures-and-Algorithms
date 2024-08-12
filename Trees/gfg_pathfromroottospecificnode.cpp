class Solution
{
    public:
    void solve(Node *root, int sum,vector<int> temp,vector<vector<int>>& result){
        if(root==NULL){
            return;
        }
        sum-=root->key;
        temp.push_back(root->key);

        if(sum==0){
            result.push_back(temp);
        }
        
        solve(root->left,sum,temp,result);
        solve(root->right,sum,temp,result);
        temp.pop_back();//back tracking
    }
    vector<vector<int>> printPaths(Node *root, int sum)
    {
        //code here
        vector<vector<int>> result;
        vector<int> temp;
        solve(root,sum,temp,result);
        return result;
    }
};
// https://www.geeksforgeeks.org/problems/paths-from-root-with-a-specified-sum/1