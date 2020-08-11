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

TreeNode *lca(TreeNode *root, TreeNode *node1, TreeNode *node2){
    if(!root)   return nullptr;

    if( root->left == node1 || root->right == node1 ||
        root->left == node2 || root->right == node2
        ){
        return root;
    }

    TreeNode *leftSubtree = lca(root->left, node1, node2);
    TreeNode *rightSubtree = lca(root->right, node1, node2);

    if(leftSubtree && rightSubtree)
        return root;
    return (!leftSubtree ? leftSubtree : rightSubtree);
}

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
