/*
    Print Right View of a Binary Tree
    https://www.geeksforgeeks.org/print-right-view-binary-tree-2/?ref=rp
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

void rightView(TreeNode *root, int level){
    static int currLvl = 0;
    if(!root)   return ;

    if(currLvl < level){
        cout << root->val << " ";
        currLvl = level;
    }

    rightView(root->right, level+1);
    rightView(root->left, level+1);
    return ;
}

// Driver function
int main(){
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);
    root->right->left = new TreeNode(6);
    root->right->right = new TreeNode(7);
    root->right->right->right = new TreeNode(8);

    // TreeNode *root = new TreeNode(4);
    // root->left = new TreeNode(5);
    // root->right = new TreeNode(2);
    // root->right->left = new TreeNode(3);
    // root->right->right = new TreeNode(1);
    // root->right->left->left = new TreeNode(6);
    // root->right->left->right = new TreeNode(7);

    rightView(root, 1);

    return 0;
}
