class Solution {
public:
    int solve(int idx,string s,unordered_set<string>& st){
        if(idx>=s.length()){
            return 0;
        }
        string str="";
        int notexcluded=INT_MAX;
        for (int i = idx; i < s.length(); i++) {
            str =s.substr(idx,i-idx+1);
            if(st.find(str)!=st.end()){
                notexcluded=solve(i+1,s,st);
            }
        }
        int excluded=1+solve(idx+1,s,st);
        return min(notexcluded,excluded);
    }
    int minExtraChar(string s, vector<string>& dictionary) {
        int idx=0;
        unordered_set<string> st (dictionary.begin(),dictionary.end());
        int ans=solve(idx,s,st);
        return ans;
    }
};