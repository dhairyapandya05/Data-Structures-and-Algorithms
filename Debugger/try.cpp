#include <bits/stdc++.h>
using namespace std;

vector<string> dictionary = {"dhairya", "dhyey", "aman", "amiab", "rhekha", "jaya", "sushma", "naman", "pankaj", "dharmesh", "dhavan"};
vector<string> filteredWords = {};
class TrieNode {
public:
    TrieNode *alphabet[26];
    bool isEnd;
    TrieNode() {
        for (int i = 0; i < 26; i++) {
            alphabet[i] = NULL;
        }
        isEnd = false;
    }
};

class Trie {
public:
    TrieNode *root;
    Trie() {
        // Write your code here.
        root = new TrieNode();
    }

    void dfs(TrieNode *temp, string searchword) {
        if (temp->isEnd) {
            filteredWords.push_back(searchword);
            return;
        }
        for (int i = 0; i < 26; i++) {
            if (temp->alphabet[i] != NULL) {
                searchword.push_back(char(i + 'a'));
                dfs(temp->alphabet[i], searchword);
                searchword.pop_back();
            }
        }
    }

    vector<string> WordsStartingWith(string searchWord) {
        // Write your code here.
        filteredWords.clear();
        TrieNode *temp = root;

        int n = searchWord.length();
        for (int i = 0; i < n; i++) {
            int ch = searchWord[i] - 'a';
            if (temp->alphabet[ch] != NULL) {
                temp = temp->alphabet[ch];
            } else {
                return filteredWords;
            }
        }
        // Now apply dfs traversal in this trie data structure
        dfs(temp, searchWord);
        return filteredWords;
    }

    void insert(string &word) {
        // Write your code here.
        TrieNode *temp = root;
        int n = word.length();
        for (int i = 0; i < n; i++) {
            int ch = word[i] - 'a';
            if (temp->alphabet[ch] == NULL) {
                TrieNode *newNode = new TrieNode();
                temp->alphabet[ch] = newNode;
            }
            temp = temp->alphabet[ch];
        }
        temp->isEnd = true;
    }
};

int main() {
    // Trie trie;
    // vector<string> wordscheck = {"amit", "doremon"};
    // int n = dictionary.size();
    // for (int i = 0; i < n; i++) {
    //     trie.insert(dictionary[i]);
    //     cout << dictionary[i] << " inserted successfully." << endl;
    // }
    // trie.WordsStartingWith("dh");
    // for (auto &word : filteredWords) {
    //     cout << word << endl;
    // }

    vector<int> arr = {5, 2, 1, 3, 4};
    int n = arr.size();
    int j = n - 1;
    for (; j >= 1; j--) {
        if (arr[j] < arr[j - 1])
            break;
    }

    cout << "J: " << arr[j];
    int k = n - 1;
    while (k > 0 && arr[k] >= arr[k - 1])
        k--;

    cout << "k: " << arr[k];

    return 0;
}