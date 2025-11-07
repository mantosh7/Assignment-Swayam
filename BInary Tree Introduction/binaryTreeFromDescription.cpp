/*
Create Binary Tree From Descriptions
You are given a 2D integer array descriptions where descriptions[i] = [parenti, childi, isLefti] indicates that parenti is the parent of childi in a binary tree of unique values. Furthermore,

If isLefti == 1, then childi is the left child of parenti.
If isLefti == 0, then childi is the right child of parenti.
Construct the binary tree described by descriptions and return its root.

The test cases will be generated such that the binary tree is valid.

Example:
Input: descriptions = [[20,15,1],[20,17,0],[50,20,1],[50,80,0],[80,19,1]]
Output: [50,20,80,15,17,19]
Explanation: The root node is the node with value 50 since it has no parent.
*/

#include <bits/stdc++.h>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

TreeNode* createBinaryTree(vector<vector<int>>& descriptions) {
    unordered_map<int, pair<TreeNode*, TreeNode*>> mp;

    for (auto &d : descriptions) {
        int parentVal = d[0];
        int childVal  = d[1];
        int isLeft    = d[2];

        if (!mp[parentVal].first)
            mp[parentVal].first = new TreeNode(parentVal);

        if (!mp[childVal].first)
            mp[childVal].first = new TreeNode(childVal);

        TreeNode* parent = mp[parentVal].first;
        TreeNode* child  = mp[childVal].first;

        if (isLeft) parent->left = child;
        else        parent->right = child;

        mp[childVal].second = parent;
    }

    for (auto &p : mp) {
        if (p.second.second == NULL)
            return p.second.first;
    }

    return NULL;
}

int main() {
    vector<vector<int>> descriptions = {
        {20, 15, 1},
        {20, 17, 0},
        {15, 10, 1}
    };

    TreeNode* root = createBinaryTree(descriptions);
    cout << root->val;
}
