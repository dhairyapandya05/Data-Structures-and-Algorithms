class Solution {
public:
    string removeDuplicates(string s) {
        string ans="";
        int i=0;
        while(i<s.length()){

        if(ans.length()>0){

            if(s[i]==ans[ans.length()-1]){
                ans.pop_back();
            }

            else{
                ans.push_back(s[i]);
            }
        }

        else
        {
            ans.push_back(s[i]);
        }

        i++;

        }
        return ans;
    }
};

// Optimised approach 
class Solution {
public:
    string st;
    string removeDuplicates(string s) {
        for (int i = 0; i < s.length(); i++) {

            if (!st.empty() and s[i] == st.back()) {
                st.pop_back();
            } else {
                st.push_back(s[i]);
            }
        }

        return st;
    }
};