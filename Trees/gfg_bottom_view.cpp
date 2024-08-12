class Solution {
  public:
  map<int,int>mp;
    vector <int> bottomView(Node *root) {
        // Your Code Here
        queue<pair<Node*,int>>qe;
        qe.push({root,0});
        // mp[0]=root->val;
        while(!qe.empty()){
            int n=qe.size();
            while(n--){
                auto frontent=qe.front();
                Node* frontNode=frontent.first;
                int col=frontent.second;
                mp[col]=frontNode->data;
                qe.pop();
                if(frontNode->left!=NULL){
                    qe.push({frontNode->left,col-1});
                }
                if(frontNode->right!=NULL){
                    qe.push({frontNode->right,col+1});
                }
            }
        }
        vector<int> ans;
        for(auto it=mp.begin();it!=mp.end();it++){
            ans.push_back(it->second);
        }
        return ans;
    }
};