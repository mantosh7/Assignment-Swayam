#include <bits/stdc++.h>
using namespace std;

struct TrieNode {
    TrieNode* child[26];
    bool isEnd;

    TrieNode() {
        isEnd = false;
        for (int i = 0; i < 26; i++)
            child[i] = NULL;
    }
};

// Insert word into Trie
void insertWord(TrieNode* root, const string &word) {
    TrieNode* curr = root;
    for (int i = 0; i < word.size(); i++) {
        int idx = word[i] - 'a';
        if (curr->child[idx] == NULL)
            curr->child[idx] = new TrieNode();
        curr = curr->child[idx];
    }
    curr->isEnd = true;
}

// Count words in Trie using DFS
int countWords(TrieNode* root) {
    if (root == NULL) return 0;

    int cnt = 0;
    if (root->isEnd) cnt++;

    for (int i = 0; i < 26; i++) {
        if (root->child[i] != NULL)
            cnt += countWords(root->child[i]);
    }

    return cnt;
}

int main() {

    vector<string> s = {
        "the", "a", "there", "answer", "any", "by", "bye", "their"
    };

    TrieNode* root = new TrieNode();

    // Insert all given words
    for (string &w : s)
        insertWord(root, w);

    cout << countWords(root);

    return 0;
}
