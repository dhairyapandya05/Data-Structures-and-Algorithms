class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        
        unordered_set<int> st(nums.begin(),nums.end());
        auto it=st.begin();
        int maxlen=0;
        for(;it!=st.end();it++){
            int element=*it;
            if(st.find(element-1)==st.end()){
                // element is definately the first element 
                int cnt=1;
                element++;
                while(st.find(element)!=st.end()){
                    cnt++;
                    element++;
                }
                maxlen=max(maxlen,cnt);
            }
        }
        return maxlen;
    }
};