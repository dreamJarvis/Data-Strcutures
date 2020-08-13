/*
    Lowest Common Ancestor in a Binary Tree
    https://www.geeksforgeeks.org/lowest-common-ancestor-binary-tree-set-1/
*/
#include <bits/stdc++.h>
using namespace std;

struct TreeNode{
    int val;
    TreeNode *left, *right;

    TreeNode(int x){
        val = x;
        left = right = nullptr;
    }
};



// Driver function
int main(){
    TreeNode *root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);
    root->right->left = new TreeNode(6);
    root->right->right = new TreeNode(6);

    TreeNode *node1 = root->left->left;
    TreeNode *node2 = root->left->right;

    cout << lca(root, node1, node2)->val << endl;

    return 0;
}
