#include <bits/stdc++.h>
using namespace std;

struct TrieNode {
    TrieNode* child[26];
    bool isEnd;

    TrieNode() {
        isEnd = false;
        for (int i = 0; i < 26; i++) child[i] = NULL;
    }
};

// Insert a word in Trie
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

// Check if node has any child
bool hasChild(TrieNode* node) {
    for (int i = 0; i < 26; i++)
        if (node->child[i] != NULL) return true;
    return false;
}

// Recursive delete function
bool deleteWord(TrieNode* root, const string &key, int depth) {
    
    if (root == NULL) return false;

    // Base case: end of key
    if (depth == key.size()) {
        // Unmark end of word
        if (root->isEnd) 
            root->isEnd = false;

        // If node has no children, inform parent to delete it
        return !hasChild(root);
    }

    int idx = key[depth] - 'a';

    if (deleteWord(root->child[idx], key, depth + 1)) {
        // Delete child pointer
        delete root->child[idx];
        root->child[idx] = NULL;

        // If current node is NOT end of another word AND has no children → delete
        return (!root->isEnd && !hasChild(root));
    }

    return false;
}

// Function to delete ALL OCCURRENCES of key in Trie
void deleteKey(TrieNode* root, const string &key) {
    deleteWord(root, key, 0);
}

// For debugging: Print words remaining in Trie
void printTrie(TrieNode* root, string &s) {
    if (root->isEnd)
        cout << s << " ";

    for (int i = 0; i < 26; i++) {
        if (root->child[i]) {
            s.push_back('a' + i);
            printTrie(root->child[i], s);
            s.pop_back();
        }
    }
}

int main() {

    int N;
    cin >> N;

    string super;
    string key;

    vector<string> words;

    // Take full sentence as input (space-separated)
    for (int i = 0; i < N; i++) {
        string temp;
        cin >> temp;
        words.push_back(temp);
    }

    cin >> key;

    TrieNode* root = new TrieNode();

    // Insert all words into Trie
    for (int i = 0; i < N; i++)
        insertWord(root, words[i]);

    // Delete all occurrences of key
    deleteKey(root, key);

    // print remaining words from Trie
    string s = "";
    printTrie(root, s);

    return 0;
}
