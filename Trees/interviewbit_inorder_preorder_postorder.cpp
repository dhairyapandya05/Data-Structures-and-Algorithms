vector<vector<int>> getTreeTraversal(TreeNode *root){
    // Write your code here.
    vector<vector<int>> ans(3,vector<int>());
    if(root == NULL) {
        return ans;
    }
    stack<pair<TreeNode*,int>> st;
    st.push({root,1});
    while (!st.empty()) {
        auto entry=st.top();
        st.pop();
        if (entry.second == 1) {
            ans[1].push_back(entry.first->data);
            entry.second=2;
            st.push(entry);
            if (entry.first->left != NULL) {
              st.push({entry.first->left,1});
            }
        }
        
        else if (entry.second == 2) {
            ans[0].push_back(entry.first->data);
            entry.second=3;
            st.push(entry);
            if (entry.first->right != NULL) {
              st.push({entry.first->right,1});
            }
        }
        else if (entry.second == 3) {
            ans[2].push_back(entry.first->data);
        }
    }
    return ans;
}
// link:https://www.naukri.com/code360/problems/981269?topList=striver-sde-sheet-problems&utm_source=striver&utm_medium=website&leftPanelTabValue=SUBMISSION
