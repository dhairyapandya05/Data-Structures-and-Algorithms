class Solution {
public:
    int scoreOfString(string s) {
        int diff=0;
        for(int i=1;i<s.length();i++){
            char ch=s[i];
            // int a=(int)ch;
            diff+=abs(int(s[i-1])-int(s[i]));
        }
        return diff;
    }
};
// https://leetcode.com/problems/score-of-a-string/description/?envType=daily-question&envId=2024-06-01