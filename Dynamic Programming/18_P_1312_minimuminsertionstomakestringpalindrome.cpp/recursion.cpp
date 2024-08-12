class Solution {
public:
    int solve(int i,int j,string& s){
        if(i>=j){
            return 0;
        }
    
        if(s[i]==s[j]){
            return solve(i+1,j-1,s);
        }
        else{
            return min(solve(i+1,j,s),solve(i,j-1,s))+1;
        }
    }
    int minInsertions(string s) {
        int n=s.length();
        int ans=solve(0,n-1,s);
        return ans;
    }
};