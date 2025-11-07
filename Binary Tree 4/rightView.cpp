/*
Given the root of a binary tree, imagine yourself standing on the right side of it, return the values of the nodes you can see ordered from top to bottom.

Exaample:
Input: root = [1,2,3,null,5,null,4]
Output: [1,3,4]
*/

#include <bits/stdc++.h>
using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

vector<int> rightSideView(TreeNode* root) {
    vector<int> ans;
    if (!root) return ans;

    queue<pair<TreeNode*, int>> q;
    map<int, TreeNode*> mp;

    q.push({root, 0});

    while (!q.empty()) {
        auto node = q.front();
        q.pop();

        TreeNode* temp = node.first;
        int level = node.second;

        mp[level] = temp;

        if (temp->left)
            q.push({temp->left, level + 1});
        if (temp->right)
            q.push({temp->right, level + 1});
    }

    for (auto it : mp)
        ans.push_back(it.second->val);

    return ans;
}

int main() {
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);

    root->left->right = new TreeNode(5);
    root->right->right = new TreeNode(4);

    vector<int> result = rightSideView(root);

    cout << "Right Side View: ";
    for (int x : result)
        cout << x << " ";
    cout << endl;

    return 0;
}
