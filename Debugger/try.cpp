#include <bits/stdc++.h>
using namespace std;
// for std::gcd

string lcs(string s1, string s2)
{
    int n = s1.size();
    int m = s2.size();

    vector<vector<int>> dp(n + 1,
                           vector<int>(m + 1, -1)); // Create a DP table

    // Initialize the base cases
    for (int i = 0; i <= n; i++)
    {
        dp[i][0] = 0;
    }
    for (int i = 0; i <= m; i++)
    {
        dp[0][i] = 0;
    }

    // Fill in the DP table to calculate the length of LCS
    for (int ind1 = 1; ind1 <= n; ind1++)
    {
        for (int ind2 = 1; ind2 <= m; ind2++)
        {
            if (s1[ind1 - 1] == s2[ind2 - 1]){
                dp[ind1][ind2] =
                    1 +
                    dp[ind1 - 1]
                      [ind2 - 1]; // Characters match, increment LCS length
            }
                
            else{
                dp[ind1][ind2] = max(
                    dp[ind1 - 1][ind2],
                    dp[ind1][ind2 - 1]); // Characters don't match, consider
                                         // the maximum from left or above
            }
                
        }
    }
    for(int i=0;i<=n;i++){
        for(int j=0;j<=m;j++){
            cout<<dp[i][j]<<" ";
        }
        cout<<endl;
    }
    int len = dp[n][m];
    int i = n, j = m;
    string ans;
    int endingidxS1=s1.length()-1;
    int endingidxS2=s2.length()-1;
    while (i >= 0 and j >= 0)
    {
        if (s1[i - 1] == s2[j - 1])
        {
            size_t indexs1 = s1.rfind(s1[i-1]);
            size_t indexs2 = s2.rfind(s2[i-1]);
            ans=s1.substr(indexs1,endingidxS1-indexs1)+ans;
            ans=s2.substr(indexs2,endingidxS2-indexs2)+ans;
            ans = s1[i - 1] + ans;
            endingidxS1=i-2;
            endingidxS2=i-2;
            
            i--;
            j--;
        }
        else if (dp[i - 1] > dp[j - 1])
        {
            i--;
        }
        else
        {
            j--;
        }
    }
    return ans;
}

int main()
{
    string str1="brute";
    string str2="groot";
    string ans=lcs(str1,str2);
    cout <<endl<< "Final Ans: " << ans;
    return 0;
}
