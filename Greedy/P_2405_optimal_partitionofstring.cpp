class Solution {
public:
    int partitionString(string s) {
        unordered_map<char,int>mp;
        int cnt=1;
        for(auto it:s){
            if(mp[it]!=0){
                cnt++;
                mp.clear();
                mp[it]++;
            }
            else{
                mp[it]++;
            }
        }
        return cnt;
    }
};