// https://leetcode.com/problems/reverse-string/submissions/1275538878/?envType=daily-question&envId=2024-06-02
class Solution {
public:
    void reverseString(vector<char>& s) {
                        int e=s.size()-1;

        // vector<char> str;
        for (int i = 0; i <= e /2; i++)
        {
            swap(s[i],s[e-i]);
        }
    }
};