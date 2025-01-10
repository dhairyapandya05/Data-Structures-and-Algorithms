#include <bits/stdc++.h>
struct Node
{
    Node *links[26];
    Node()
    {
        for (int i = 0; i < 26; i++)
        {
            links[i] = NULL;
        }
    }

    bool containsKey(char ch)
    {
        return links[ch - 'a'] != NULL;
    }

    Node *get(char ch)
    {
        return links[ch - 'a'];
    }

    void put(char ch, Node *node)
    {
        links[ch - 'a'] = node;
    }
};

class Trie
{
private:
    Node *root;

public:
    Trie()
    {
        root = new Node();
    }
};

int countDistinctSubstrings(string &s)
{
    //    Write your code here.
    Node *root = new Node();
    int n = s.length();
    int cnt = 0;
    for (int i = 0; i < n; i++)
    {
        Node *temp = root;
        for (int j = i; j < n; j++)
        {
            if (!temp->containsKey(s[j]))
            {
                temp->put(s[j], new Node());
                cnt++;
            }
            temp = temp->get(s[j]);
        }
    }
    return cnt + 1; // 1 for including the empty sub
}