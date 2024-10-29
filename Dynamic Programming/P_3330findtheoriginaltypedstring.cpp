class Solution
{
public:
    unordered_map<string, bool> mp;
    void solve(int i, string temp, set<string> &st, string &word,
               bool startmistake)
    {
        // base cases
        if (i == word.length())
        {
            st.insert(temp);
            return;
        }
        string key = to_string(i) + "|" + temp + "|" + to_string(startmistake);
        if (mp.find(key) != mp.end())
            return;
        int k = temp.length();
        if (startmistake == true and temp[k - 1] != word[i])
        {
            temp += word.substr(i, word.length() - i + 1);
            st.insert(temp);
            mp[key] = true; // Mark the current state as visited
            return;
        }

        if (temp[k - 1] == word[i])
        {
            // we have two choices of taking it
            // skip
            solve(i + 1, temp, st, word, true);
            // take
            solve(i + 1, temp + word[i], st, word, startmistake);
        }
        else
        {
            // take
            solve(i + 1, temp + word[i], st, word, startmistake);
        }
        mp[key] = true; // Mark the current state as visited
    }
    int possibleStringCount(string word)
    {
        string temp = string(1, word[0]);
        int i = 1;
        bool startmistake = false;
        set<string> st;
        solve(i, temp, st, word, startmistake);
        return st.size();
    }
};

// Approach 2
class Solution
{
public:
    int possibleStringCount(string word)
    {
        vector<int> repetation;
        int n = word.length();
        char lastch = word[0];
        int cnt = 0;
        for (int i = 1; i < n; i++)
        {
            if (word[i] == lastch)
            {
                cnt++;
            }
            else
            {
                if (cnt == 0)
                {
                    lastch = word[i];
                    continue;
                }
                else
                {
                    repetation.push_back(cnt);
                    lastch = word[i];
                    cnt = 0;
                }
            }
        }
        if (cnt > 0)
        {
            repetation.push_back(cnt);
        }
        int finalans = 0;
        for (auto it : repetation)
        {
            finalans += it;
        }
        return finalans + 1;
    }
};