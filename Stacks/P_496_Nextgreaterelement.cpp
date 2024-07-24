class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        int n=nums2.size();
        vector<int> ans(n);
        stack<int> st;
        st.push(-1);
        for(int i=n-1;i>=0;i--){
            while(st.top()<nums2[i] and st.top()!=-1){
                st.pop();
            }
            ans[i]=st.top();
            st.push(nums2[i]);
        }
        vector<int> finalans;
        for(auto&it:nums1){
            auto itr=find(nums2.begin(),nums2.end(),it);
            if(itr!=nums2.end()){
                int idx=distance(nums2.begin(),itr);
                finalans.push_back(ans[idx]);
            }
        }
        return finalans;
    }
};