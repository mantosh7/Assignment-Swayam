#include <bits/stdc++.h>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

TreeNode* buildTree(const vector<int> &arr) {
    if(arr.empty() || arr[0] == -1) return NULL;

    TreeNode* root = new TreeNode(arr[0]);
    queue<TreeNode*> q;
    q.push(root);

    int i = 1;

    while(!q.empty() && i < arr.size()) {
        TreeNode* node = q.front();
        q.pop();

        // left child
        if(i < arr.size() && arr[i] != -1) {
            node->left = new TreeNode(arr[i]);
            q.push(node->left);
        }
        i++;

        // right child
        if(i < arr.size() && arr[i] != -1) {
            node->right = new TreeNode(arr[i]);
            q.push(node->right);
        }
        i++;
    }

    return root;
}


int main() {
    vector<int> arr = {1, 2, 3, -1, 4};

    TreeNode* root = buildTree(arr);

    queue<TreeNode*> q ;
    q.push(root) ;

    while(!q.empty())
    {
        int s = q.size() ;

        for(int i=0;i<s;i++)
        {
            TreeNode* node = q.front() ;
            q.pop() ;
            cout<<node->val<<" " ;

            if(node->left != NULL) q.push(node->left) ;
            if(node->right != NULL) q.push(node->right) ;
        }
    }
}
