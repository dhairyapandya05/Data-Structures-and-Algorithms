class Solution {
public:
    bool isAnagram(string s, string t) {
    //     sort(s.begin(),s.end());
    //     sort(t.begin(),t.end());

    //     for(int i=0;i<s.size()||i<t.size();i++){
    //         if(s[i]!=t[i]){
    //             return false;
    //         }
    //     }
    // return true;


    // #2
    // Method 2
    int hash[256]={0};
    for(int i=0;i<s.size();i++){
        hash[s[i]]++;
    }

    //traverse and make them zero
    for(int i=0;i<t.size();i++)
    {
        hash[t[i]]--;
    }

    // check for zero
    for(int i=0;i<sizeof(hash)/sizeof(hash[0]);i++){
        if(hash[i]!=0){
            return false;
        }
    }
    return true;
    }
};