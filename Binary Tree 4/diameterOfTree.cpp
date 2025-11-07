/*
Given the root of a binary tree, return the length of the diameter of the tree.
The diameter of a binary tree is the length of the longest path between any two nodes in a tree. This path may or may not pass through the root.
The length of a path between two nodes is represented by the number of edges between them.

Example:
Input: root = [1,2,3,4,5]
Output: 3
Explanation: 3 is the length of the path [4,2,1,3] or [5,2,1,3].
*/

#include <bits/stdc++.h>
using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

int height(TreeNode* root, int& maxi) {
    if (root == NULL) return 0;

    int left  = height(root->left, maxi);
    int right = height(root->right, maxi);

    maxi = max(maxi, left + right);

    return max(left, right) + 1;
}

int diameterOfBinaryTree(TreeNode* root) {
    int maxi = 0;
    height(root, maxi);
    return maxi;
}

int main() {
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);

    cout << "Diameter = " << diameterOfBinaryTree(root) << endl;

    return 0;
}
