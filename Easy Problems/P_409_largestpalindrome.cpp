class Solution {
public:
    int longestPalindrome(string s) {
        unordered_map<int,int> map;
        for(auto& it:s){
            map[it-'a']++;
        }
        int result=0;
        bool oddpresent=false;
        for(auto it=map.begin();it!=map.end();it++){
            if(it->second%2==1){
                result+=(it->second-1);
                oddpresent=true;
            }
            if(it->second%2==0){
                result+=it->second;
            }
        }
        return (oddpresent)?result+1:result;
    }
};