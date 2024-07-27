    int shortestCommonSupersequence(string str1, string str2, int m, int n)
    {
        //code here
        vector<vector<int>> dp(m+1,vector<int>(n+1,0));
        for(int i=str1.length()-1;i>=0;i--){
            for(int j=str2.length()-1;j>=0;j--){
                int ans=0;
                if(str1[i]==str2[j]){
                    ans=1+dp[i+1][j+1];
                }
                else{
                    ans=max(dp[i+1][j],dp[i][j+1]);
                }
                dp[i][j]=ans;
            }
        }
        int lcs= dp[0][0];
        int commoninstr1=str1.length()-lcs;
        int commoninstr2=str2.length()-lcs;
        return lcs+commoninstr1+commoninstr2;
    }
};