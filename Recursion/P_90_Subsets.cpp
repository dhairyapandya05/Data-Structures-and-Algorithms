class Solution {
public:
    void solve(int idx,vector<int>& nums,set<vector<int>>& st,vector<int>& temp){
        if(idx>=nums.size()){
            st.insert({temp});
            return;
        }
        //include
        temp.push_back(nums[idx]);
        solve(idx+1,nums,st,temp);
        temp.pop_back();
        //exclude
        solve(idx+1,nums,st,temp);
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        set<vector<int>> st;
        vector<int> temp;
        solve(0,nums,st,temp);
        vector<vector<int>> ans;
        for(auto i=st.begin();i!=st.end();i++){
            ans.push_back(*i);
        }
        return ans;
    }
};