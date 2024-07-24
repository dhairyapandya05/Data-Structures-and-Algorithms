class Solution {
public:
bool palindromecheck(string &s,int i,int j)
{
    while(i<j){
            if(s[i] != s[j]){
                return false;
            }
            i++;
            j--;
        }
        return true;
}

public:
    string longestPalindrome(string s) {
    string substring;
        int maxlen=0;
int startingindex=0;
    string finalresult;
    int substringlength = 0;
    bool result;
for (int i = 0; i <= s.length() - 1; i++){
        for (int j = i; j <= s.size(); j++)
        {

            result = palindromecheck(s,i,j);
            if (result)//palindrome hai bhai
            {
                if(j-i+1 > maxlen){
                        maxlen = j-i+1;
                        startingindex = i;
                    }
            }
        }
    }

    return s.substr(startingindex,maxlen);
//can also be solved using dp dynamic programming
    
    }
};
// can also be solved using dynamic programming