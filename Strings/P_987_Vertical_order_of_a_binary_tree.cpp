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
    
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        auto cmp=[&](pair<int,int>& a,pair<int,int>& b){
            if(a.first==b.first){
                return a.second<b.second;
            }
            return a.first<b.first;
        };
        queue<pair<TreeNode*,int>> qe;
        map<int,vector<pair<int,int>>>mp;
        qe.push({root,0});
        int level=-1;
        while(!qe.empty()){
            int n=qe.size();
            level++;
            while(n--){
                auto entry=qe.front();
                qe.pop();
                auto node=entry.first;
                int x_cordinate=entry.second;
                mp[x_cordinate].push_back({level,node->val});
                if(node->left!=NULL){
                    qe.push({node->left,x_cordinate-1});
                }
                if(node->right!=NULL){
                    qe.push({node->right,x_cordinate+1});
                }
            }
        }
        for(auto it=mp.begin();it!=mp.end();it++){
            sort(it->second.begin(),it->second.end(),cmp);
        }
        vector<vector<int>> ans;
        for(auto it=mp.begin();it!=mp.end();it++){
            vector<int>temp;
            for(auto ent:it->second){
                temp.push_back(ent.second);
            }
            ans.push_back(temp);
        }
        return ans;
    }
};