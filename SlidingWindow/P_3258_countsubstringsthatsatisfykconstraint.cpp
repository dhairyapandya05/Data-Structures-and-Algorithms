// Approach-1 (Using Brute Force)
// T.C : O(n^2)
// S.C : O(1)
class Solution
{
public:
    int countKConstraintSubstrings(string s, int k)
    {
        int n = s.length();

        int result = 0;

        for (int i = 0; i < n; i++)
        {

            int count0 = 0;
            int count1 = 0;

            for (int j = i; j < n; j++)
            {
                if (s[j] == '0')
                {
                    count0++;
                }
                else
                {
                    count1++;
                }

                if (count0 <= k || count1 <= k)
                {
                    result += 1;
                }
                else
                {
                    break;
                }
            }
        }

        return result;
    }
};

// Approach 2
class Solution
{
public:
    int countKConstraintSubstrings(string s, int k)
    {
        int i = 0, j = 0;
        int n = s.length();
        int zerocnt = 0, onecnt = 0;
        int result = 0;
        while (j < n)
        {
            if (s[j] == '0')
            {
                zerocnt++;
            }
            else
            {
                onecnt++;
            }
            while (i <= j and (zerocnt > k and onecnt > k))
            {
                if (s[i] == '0')
                {
                    zerocnt--;
                }
                else
                {
                    onecnt--;
                }
                i++;
            }
            result += (j - i + 1);
            j++;
        }
        return result;
    }
};