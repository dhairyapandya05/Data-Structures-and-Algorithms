class Solution
{
    public:
    //Function to return a list of nodes visible from the top view 
    //from left to right in Binary Tree.
    map<int,int>mp;
    vector<int> topView(Node *root)
    {
        //Your code here
        queue<pair<Node*,int>> qe;
        qe.push({root,0});
        while(!qe.empty()){
            auto entry=qe.front();
            qe.pop();
            Node* node=entry.first;
            int level=entry.second;
            if(mp.find(level)==mp.end()){
                mp[level]=node->data;
            }
            if(node->left!=NULL){
                qe.push({node->left,level-1});
            }
            if(node->right!=NULL){
                qe.push({node->right,level+1});
            }
        }
        vector<int> topview;
        for(auto it=mp.begin();it!=mp.end();it++){
            topview.push_back(it->second);
        }
        return topview;
    }

};
link:https://www.geeksforgeeks.org/problems/top-view-of-binary-tree/1