class Solution {
public:
    string reversePrefix(string word, char ch) {
        int j = word.find(ch);
        int i=0;
        while(i<=j){
            swap(word[i],word[j]);
            i++;
            j--;
        }
        // reverse(word.begin(), word.begin() + j + 1);
        return word;
    }
};