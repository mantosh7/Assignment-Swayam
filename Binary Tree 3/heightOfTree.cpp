/*
Given the root of a binary tree, return its maximum depth.
A binary tree's maximum depth is the number of nodes along the longest path from the root node down to the farthest leaf node.

Example:
Input: root = [3,9,20,null,null,15,7]
Output: 3
*/

#include <bits/stdc++.h>
using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

int maxDepth(TreeNode* root) {
    if (root == NULL) return 0;

    stack<pair<TreeNode*, int>> st;
    st.push({root, 1});

    int maxDepthVal = 0;

    while (!st.empty()) {
        auto node = st.top();
        st.pop();

        TreeNode* curr = node.first;
        int depth = node.second;

        maxDepthVal = max(maxDepthVal, depth);

        if (curr->left)  st.push({curr->left, depth + 1});
        if (curr->right) st.push({curr->right, depth + 1});
    }

    return maxDepthVal;
}

int main() {
    /*
        Tree Example:
                1
               / \
              2   3
             / \
            4   5
    */

    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);

    cout << "Max Depth = " << maxDepth(root) << endl;

    return 0;
}
