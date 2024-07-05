class Solution {
public:

int firstoccurance(vector<int> vec, int target)
{
    int s = 0, e = vec.size() - 1, m = s + (e - s) / 2;
    int firstoccurance=-1;
    for (int i = 0; s <= e; i++)
    {
        if (target < vec[m])
        {
            e = m - 1;
        }
        else if (target == vec[m])
        {
            firstoccurance = m;
            e = m - 1;
        }
        else
        {
            s = m + 1;
        }
        m = s + (e - s) / 2;
    }

    return firstoccurance;
}


int lastoccurance(vector<int> vec, int target)
{
    int s = 0, e = vec.size() - 1, m = s + (e - s) / 2;
    int lastoccurance=-1;
    for (int i = 0; s <= e; i++)
    {
        if (target < vec[m])
        {
            e = m - 1;
        }
        else if (target == vec[m])
        {
            lastoccurance = m;
            s = m + 1;
        }
        else
        {
            s = m + 1;
        }
        m = s + (e - s) / 2;
    }

    return lastoccurance;
}

    vector<int> searchRange(vector<int>& v, int target) {
        vector<int> ans;
        ans.push_back(firstoccurance(v, target));
        ans.push_back(lastoccurance(v, target));
        return ans;
    }
};