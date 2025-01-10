#include <bits/stdc++.h>

struct Node
{
    Node *links[26];
    bool flag = false;

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

    void setEnd()
    {
        flag = true;
    }

    bool isEnd()
    {
        return flag;
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

    void insert(string word)
    {
        Node *temp = root;
        for (int i = 0; i < word.length(); i++)
        {
            char ch = word[i];
            if (!temp->containsKey(ch))
            {
                temp->put(ch, new Node());
            }
            temp = temp->get(ch);
        }
        temp->setEnd();
    }

    bool checkIfPrefixExists(string word)
    {
        Node *node = root;
        for (int i = 0; i < word.length(); i++)
        {
            char ch = word[i];
            if (node->containsKey(ch))
            {
                node = node->get(ch);
                if (!node->isEnd())
                    return false;
            }
            else
            {
                return false;
            }
        }
        return true;
    }
};

string completeString(int n, vector<string> &a)
{
    // Write your code here.
    Trie trie;
    for (auto it : a)
    {
        trie.insert(it);
    }

    string longest = "";
    for (auto it : a)
    {
        if (trie.checkIfPrefixExists(it))
        {
            if (it.length() > longest.length())
            {
                longest = it;
            }
            else if (it.length() == longest.length() && it < longest)
            {
                longest = it;
            }
        }
    }

    return longest == "" ? "None" : longest;
}