class Solution {
public:
    int maxLengthBetweenEqualCharacters(string s) {
        // int start=0;
        // int end=s.length()-1;
        // while(start < end){
        //     if(start == end){
        //         return 0;
        //     }
        //     if(s[start]==s[end]){
        //         return (end-start)-1;
        //     }
        //     else{
        //         start++;
        //         end--;
        //         continue;
        //     }


        // }
        // return -1;
        unordered_map <char,int> hash;
        // initialise
        int difference=-1;
        for(char ch='a';ch<='z';ch++){
            hash[ch]=-1;
        }
        for(int i=0;i<s.length();i++){
            if(hash[s[i]]==-1)
            hash[s[i]]=i;
            else{
                difference=max(difference,i-hash[s[i]]-1);
            }
        }
        return difference;

    }
};