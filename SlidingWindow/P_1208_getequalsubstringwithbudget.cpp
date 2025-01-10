class Solution
{
public:
    int equalSubstring(string s, string t, int maxCost)
    {
        int i = 0, j = 0, n = s.length();
        int result = 0;
        int cost = 0;
        while (j < n)
        {
            cost += abs(int(s[j] - 'a') - int(t[j] - 'a'));
            while (i <= j and cost > maxCost)
            {
                cost -= abs(s[i] - t[i]);
                i++;
            }
            result = max(result, j - i + 1);
            j++;
        }
        return result;
    }
};