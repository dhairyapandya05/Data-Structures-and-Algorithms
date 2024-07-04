// class Solution {
// public:
//     bool makeEqual(vector<string>& words) {
//         // unordered_map<char,int>map(26,0);
//         unordered_map<char, int> myMap;
    
//     // Initialize the map with 26 keys ('a' to 'z') and set all values to 0
//     for (char ch = 'a'; ch <= 'z'; ++ch) {
//         myMap[ch] = 0;
//     }
//         int countLett=0;
//         int countele=0;
//         for(auto i:words){
//             for(auto j:i){
//                 myMap[j]++;
//                 countLett++;
                
//             }
//             countele++;
//         }
//         if(countLett==1 && countele==1){
//             return true;
//         }
//         if(countLett==countele){
//             return false;
//         }
//         int occurance=countLett/countele;
//         for(int i=0;i<26;i++){
//             if (myMap[i]!=occurance && countLett%countele != 0){
//                 return false;
//             }
//         }
//         // we have traversed to the final character in the string
//         // if(countLett%countele==0){
//         //     return true;
//         // }
//         // else{
//             return true;
//         // }

//     }
// };
class Solution {
public:
    bool makeEqual(vector<string>& words) {
        if (words.size() == 1) {
            return true;
        }

        int totalCharCount = 0;
        for (const string& s : words) {
            totalCharCount += s.length();
        }

        if (totalCharCount % words.size() != 0) {
            return false;
        }

        vector<int> myMap(26, 0);
        for (const string& s : words) {
            for (char c : s) {
                myMap[c - 'a']++;
            }
        }

        for (int i : myMap) {
            if (i % words.size() != 0) {
                return false;
            }
        }

        return true;
    }
};