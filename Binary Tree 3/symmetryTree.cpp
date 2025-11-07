/*
Given the root of a binary tree, check whether it is a mirror of itself (i.e., symmetric around its center).
Example:
Input: root = [1,2,2,3,4,4,3]
Output: true
*/

#include <bits/stdc++.h>
using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

bool checkSymmetry(TreeNode* leftRoot, TreeNode* rightRoot) {
    if (leftRoot == NULL || rightRoot == NULL)
        return leftRoot == rightRoot;

    if (leftRoot->val != rightRoot->val)
        return false;

    bool leftMirror  = checkSymmetry(leftRoot->left, rightRoot->right);
    bool rightMirror = checkSymmetry(leftRoot->right, rightRoot->left);

    return leftMirror && rightMirror;
}

bool isSymmetric(TreeNode* root) {
    if (root == NULL) return true;
    return checkSymmetry(root->left, root->right);
}

int main() {
    /*
            1
           / \
          2   2
         / \ / \
        3  4 4  3
    */

    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(2);

    root->left->left = new TreeNode(3);
    root->left->right = new TreeNode(4);

    root->right->left = new TreeNode(4);
    root->right->right = new TreeNode(3);

    cout << (isSymmetric(root) ? "Symmetric" : "Not Symmetric") << endl;

    return 0;
}
