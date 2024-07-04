class Solution {
public:
    int maxDepth(string s) {
        int finalans=INT_MIN;
        int ans=0;
        for(int i=0;i<s.length();i++){
            if(s[i]=='('){
                ans++;
            }
            if(s[i]==')'){
                finalans=max(ans,finalans);
                ans--;
            }
            else{
                continue;
            }
        }
        return (finalans==INT_MIN)?0:finalans;
    }
};