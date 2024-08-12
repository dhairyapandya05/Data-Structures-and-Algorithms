class Solution{
  public:
    long long findRank(string str) {
        //code here
        vector<long long> fact(26,1);
        fact[0]=1;
        for(int i=1;i<25;i++){
            fact[i]=i*fact[i-1];
        }
        long long ans=0;
        int n=str.length();
        vector<int>strFreq (256,0);
        for(auto& ch:str){
            strFreq[ch]++;
        }
        for(int i=0;i<n;i++){
            int numberofletterssmaller=0;
            for(int j=0;j<256;j++){
                if(j==str[i]){
                    break;
                }
                if(strFreq[j]){
                    numberofletterssmaller++;
                }
            }
            ans+=numberofletterssmaller*fact[n-i-1];
            strFreq[str[i]]--;
        }
        return ans+1;
    }
};
// link:https://www.geeksforgeeks.org/problems/rank-the-permutations2229/1