class Solution
{
public:
    string reverseWords(string s)
    {
        stringstream ss(s);
        string token = "";
        string result = "";
        while (ss >> token)
        {
            result = token + " " + result;
        }
        result = result.substr(0, result.length() - 1);
        return result;
    }
};