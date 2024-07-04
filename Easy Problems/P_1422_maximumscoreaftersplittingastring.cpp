class Solution {
public:
    int cntsetbits(string s){
        int count=0;
        for(int i=0;i<s.length();i++){
            if(s[i]=='1'){
                count++;
            }
        }
        return count;
    }
    int maxScore(string s) {
        int setbits=cntsetbits(s);
        int rightzeros=0;
        int ans=INT_MIN;
        for(int i=0;i<s.length()-1;i++){
            if(s[i]=='0'){
                ++rightzeros;
            }
            if(s[i]=='1'){
                --setbits;
            }
            ans=max(ans,setbits+rightzeros);
        }
        return ans;
    }
};