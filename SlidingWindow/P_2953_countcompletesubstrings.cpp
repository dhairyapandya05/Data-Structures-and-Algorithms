class Solution
{
public:
    int solve(int s, int e, string &word, int &k)
    {
        int result = 0;
        for (int uniquech = 1; uniquech <= 26 and (uniquech * k <= e - s + 1); uniquech++)
        {
            vector<int> count(26, 0);
            int goodBoy = 0;
            // Now, start sliding window

            int i = s;
            int windowLength = uniquech * k;
            for (int j = s; j <= e; j++)
            {
                char ch = word[j];
                count[ch - 'a']++;
                if (count[ch - 'a'] == k)
                {
                    goodBoy += 1;
                }
                else if (count[ch - 'a'] == k + 1)
                {
                    goodBoy -= 1;
                }

                if (j - i + 1 > windowLength)
                {
                    if (count[word[i] - 'a'] == k)
                    {
                        goodBoy -= 1;
                    }
                    else if (count[word[i] - 'a'] == k + 1)
                    {
                        goodBoy += 1;
                    }
                    count[word[i] - 'a']--;
                    i++;
                }
                if (goodBoy == uniquech)
                {
                    result += 1;
                }
            }
        }
        return result;
    }
    int countCompleteSubstrings(string word, int k)
    {
        int last = 0;
        int n = word.length();
        int result = 0;
        for (int i = 1; i <= n; i++)
        {
            if (i == n or abs(word[i] - word[i - 1]) > 2)
            {
                result += solve(last, i - 1, word, k);
                last = i;
            }
        }
        return result;
    }
};