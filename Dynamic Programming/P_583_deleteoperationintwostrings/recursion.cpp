// n+m-2(lcs)

// and copy the code 
class Solution {
public:
int solve(int i,int j,string& txt1,string& txt2){
        if(i>=txt1.length() or j>=txt2.length()){
            return 0;
        }
        int ans=0;
        if(txt1[i]==txt2[j]){
            ans=1+solve(i+1,j+1,txt1,txt2);
        }
        else{
            ans=max(solve(i+1,j,txt1,txt2),solve(i,j+1,txt1,txt2));
        } 
        return ans;
    }
    int minDistance(string word1, string word2) {
        int ans=solve(0,0,word1,word2);
        return word1.length()+word2.length()-(2*ans);
    }
};