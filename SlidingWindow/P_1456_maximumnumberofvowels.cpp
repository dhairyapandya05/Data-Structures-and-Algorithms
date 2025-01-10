class Solution
{
public:
    bool isVowel(char &ch)
    {
        return ch == 'a' or ch == 'e' or ch == 'i' or ch == 'o' or ch == 'u';
    }
    int maxVowels(string s, int k)
    {
        int l = 0, r = 0, n = s.length();
        int vowels = 0;
        int ans = 0;
        while (l < n)
        {
            if (isVowel(s[l]))
            {
                vowels++;
            }
            if (l - r + 1 == k)
            {
                ans = max(vowels, ans);
                if (isVowel(s[r]))
                {
                    vowels--;
                }
                r++;
            }

            l++;
        }
        return ans;
    }
};