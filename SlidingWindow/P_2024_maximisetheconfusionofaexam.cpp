// Method 1
class Solution
{
public:
    int maxConsecutiveAnswers(string answerKey, int k)
    {
        // turning t to f

        int totalT = 0;
        int totalF = 0;
        int maxL = 0;
        int i = 0, j = 0, n = answerKey.length();
        while (j < n)
        {
            if (answerKey[j] == 'T')
            {
                totalT++;
            }
            while (totalT > k)
            {
                if (answerKey[i] == 'T')
                {
                    totalT--;
                }
                i++;
            }
            maxL = max(maxL, j - i + 1);
            j++;
        }
        i = 0, j = 0; // resetting
        while (j < n)
        {
            if (answerKey[j] == 'F')
            {
                totalF++;
            }
            while (totalF > k)
            {
                if (answerKey[i] == 'F')
                {
                    totalF--;
                }
                i++;
            }
            maxL = max(maxL, j - i + 1);
            j++;
        }
        return maxL;
    }
};

// Method 2 most optimised version of the above algorithm
class Solution
{
public:
    int maxConsecutiveAnswers(string answerKey, int k)
    {
        // turning t to f

        int totalT = 0;
        int totalF = 0;
        int maxL = 0;
        int i = 0, j = 0, n = answerKey.length();
        while (j < n)
        {
            if (answerKey[j] == 'T')
            {
                totalT++;
            }
            else
            {
                totalF++;
            }
            int mini = min(totalT, totalF);
            while (mini > k)
            {
                if (answerKey[i] == 'F')
                {
                    totalF--;
                }
                else
                {
                    totalT--;
                }
                i++;
                mini = min(totalT, totalF);
            }
            maxL = max(maxL, j - i + 1);
            j++;
        }
        return maxL;
    }
};