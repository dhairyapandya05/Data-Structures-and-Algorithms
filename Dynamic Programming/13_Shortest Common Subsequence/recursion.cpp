class Solution
{
    public:
    int solve(string& str1, string& str2, int i,int j,int& m, int& n){
        if(i>=m){
            return n-j;
        }
        if(j>=n){
            return m-i;
        }
        int ans=INT_MAX;
        if(str1[i]==str2[j]){
            ans=1+solve(str1,str2,i+1,j+1,m,n);
        }
        else{
            ans=min(solve(str1,str2,i+1,j,m,n),solve(str1,str2,i,j+1,m,n))+1;
        }
        return ans;
    }
    //Function to find length of shortest common supersequence of two strings.
    int shortestCommonSupersequence(string X, string Y, int m, int n)
    {
        //code here
        int ans=solve(X,Y,0,0,m,n);
        return ans;
    }
};