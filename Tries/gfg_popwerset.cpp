// Link: https :www.geeksforgeeks.org/problems/power-set4302/1

class Solution
{
public:
    vector<string> AllPossibleStrings(string s)
    {
        // Code here
        int n = s.length();
        vector<string> st;
        for (int i = 0; i < (1 << n); i++)
        {
            string temp = "";
            for (int j = 0; j < n; j++)
            {
                if ((i & (1 << j)) != 0)
                {
                    temp += s[j];
                }
            }
            if (temp.length() > 0)
                st.push_back(temp);
        }

        sort(st.begin(), st.end());
        return st;
    }
};