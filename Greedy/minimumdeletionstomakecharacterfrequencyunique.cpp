class Solution {
public:
    int minDeletions(string s) {
        vector<int> freq(26,0);
        for(auto it:s){
            freq[it-'a']++;
        }
        set<int> st;
        int operations=0;
        for(int i=0;i<26;i++){
            while(st.find(freq[i])!=st.end()){
                operations++;
                freq[i]--;
            }
            if(freq[i]!=0){
                st.insert(freq[i]);
            }
        }
        return operations;
    }
};