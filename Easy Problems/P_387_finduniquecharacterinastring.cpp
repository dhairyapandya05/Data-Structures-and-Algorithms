class Solution {
public:
    int firstUniqChar(string s) {
        unordered_map<int,int> map;
        for(auto& ch :s){
            map[ch-'a']++;
        }
        for(int i=0;i<s.length();i++){
            if(map[s[i]-'a']==1){
                return i;
            }
        }
        return -1;
    }
};