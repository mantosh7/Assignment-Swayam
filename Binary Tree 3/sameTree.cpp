/*
Given the roots of two binary trees p and q, write a function to check if they are the same or not.
Two binary trees are considered the same if they are structurally identical, and the nodes have the same value.

Example:
Input: p = [1,2,3], q = [1,2,3]
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

bool checkTree(TreeNode* root1, TreeNode* root2) {
    if (root1 == NULL && root2 == NULL) return true;
    if (root1 == NULL || root2 == NULL) return false;
    if (root1->val != root2->val) return false;

    bool leftSame = checkTree(root1->left, root2->left);
    bool rightSame = checkTree(root1->right, root2->right);

    return leftSame && rightSame;
}

bool isSameTree(TreeNode* p, TreeNode* q) {
    return checkTree(p, q);
}

int main() {
    TreeNode* p = new TreeNode(1);
    p->left = new TreeNode(2);
    p->right = new TreeNode(3);

    TreeNode* q = new TreeNode(1);
    q->left = new TreeNode(2);
    q->right = new TreeNode(3);

    cout << (isSameTree(p, q) ? "Same" : "Not Same") << endl;

    return 0;
}
