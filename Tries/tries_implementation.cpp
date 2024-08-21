#include <bits/stdc++.h>
class TrieNode {
    public:
    TrieNode* alphabet[26];
    int count;
    bool isEnd;
    TrieNode() {
        for (int i = 0; i < 26; i++) {
            alphabet[i]=NULL;
        }
        count=0;
        isEnd=false;
    }
};
 class Trie {

public:
    TrieNode* root;
  Trie() {
    // Write your code here.
    root=new TrieNode();
  }

    int countAllWordsFromNode(TrieNode* node) {
        if (node == NULL) return 0;
        int count = node->isEnd ? node->count : 0;
        for (int i = 0; i < 26; i++) {
            if (node->alphabet[i] != NULL) {
                count += countAllWordsFromNode(node->alphabet[i]);
            }
        }
        return count;
    }
  void insert(string &word) {
    // Write your code here.
    TrieNode* temp=root;
    int n=word.length();
    for (int i = 0; i < n; i++) {
        int ch=word[i]-'a';
        if (temp->alphabet[ch] == NULL) {
            TrieNode* newNode = new TrieNode();
            temp->alphabet[ch]=newNode;
        }
        temp=temp->alphabet[ch];
    }
    temp->isEnd=true;
    temp->count++;
  }

  int countWordsEqualTo(string &word) {
    // Write your code here.
    TrieNode* temp=root;

    int n=word.length();
    for (int i = 0; i < n; i++) {
        int ch=word[i]-'a';
        if (temp->alphabet[ch] != NULL) {
            temp=temp->alphabet[ch];
        } else {
            return 0;
        } 
    }
    return temp->isEnd ? temp->count : 0;
  }

  int countWordsStartingWith(string &word) {
    // Write your code here.
    TrieNode* temp=root;

    int n=word.length();
    for (int i = 0; i < n; i++) {
        int ch=word[i]-'a';
        if (temp->alphabet[ch] != NULL) {
            temp=temp->alphabet[ch];
        } else {
            return 0;
        } 
    }
    
    // int totalcnt=temp->count;
    // for (int i = 0; i < 26; i++) {
    //     if (temp->alphabet[i] != NULL) {
    //         temp=temp->alphabet[i];
    //         if (temp->isEnd) {
    //             totalcnt+=temp->count;
    //         }
    //     }
    // }
    return countAllWordsFromNode(temp);
    // return totalcnt;
  }

  void erase(string &word) {
    // Write your code here.
    TrieNode* temp=root;

    int n=word.length();
    for (int i = 0; i < n; i++) {
        int ch=word[i]-'a';
        if (temp->alphabet[ch] != NULL) {
            temp=temp->alphabet[ch];
        } else {
            return;
        } 
    }
    temp->count--;
  }
};
