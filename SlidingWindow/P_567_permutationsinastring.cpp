class Solution
{
public:
    bool checkInclusion(string s1, string s2)
    {
        vector<int> req(26, 0);
        for (auto it : s1)
        {
            req[it - 'a']++;
        }
        int n = s2.length();
        int m = s1.length();
        if (m > n)
        {
            return false;
        }
        for (int i = 0, j = 0; j < n;)
        {
            req[s2[j] - 'a']--;
            if (j - i + 1 > m)
            {
                req[s2[i] - 'a']++;
                i++;
            }
            if (req == vector<int>(26, 0))
            {
                return true;
            }
            j++;
        }
        return false;
    }
};