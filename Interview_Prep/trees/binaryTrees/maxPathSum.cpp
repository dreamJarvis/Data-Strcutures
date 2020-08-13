/*
    Leetcode 124. Binary Tree Maximum Path Sum
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

// O(n)
int maxSum(TreeNode *root, int &res){
    if(!root)   return 0;

    int l = maxSum(root->left, res);
    int r = maxSum(root->right, res);

    int withoutChid = max(max(l, r)+root->val, root->val);
    int withChild = max(l+r+root->val, withoutChid);
    res = max(res, withChild);

    return withoutChid;
}

int maxPathSum(TreeNode* root) {
    int res = INT_MIN;
    maxSum(root, res);

    return res;
}

// Driver function
int main(){
    TreeNode *root = new TreeNode(-10);
    root->left = new TreeNode(9);
    root->right = new TreeNode(20);
    root->right->left = new TreeNode(15);
    root->right->right= new TreeNode(7);

    // TreeNode *root = new TreeNode(1);
    // root->left = new TreeNode(-2);
    // root->right = new TreeNode(3);

    // TreeNode *root = new TreeNode(5);
    // root->left = new TreeNode(4);
    // root->right = new TreeNode(8);
    // root->left->left = new TreeNode(11);
    // root->left->left->left = new TreeNode(7);
    // root->left->left->right = new TreeNode(2);
    // root->right->left = new TreeNode(13);
    // root->right->right = new TreeNode(4);
    // root->right->right->right = new TreeNode(1);

    // TreeNode *root = new TreeNode(1);
    // root->left = new TreeNode(-2);
    // root->right = new TreeNode(-3);
    // root->left->left = new TreeNode(1);
    // root->left->right= new TreeNode(3);
    // root->right->left = new TreeNode(-2);
    // root->right->left->left = new TreeNode(-1);

    // TreeNode *root = new TreeNode(-1);
    // root->left = new TreeNode(5);
    // root->left->left = new TreeNode(4);
    // root->left->left->right= new TreeNode(-4);
    // root->left->left->left = new TreeNode(2);

    // TreeNode *root = new TreeNode(-1);
    // root->left = new TreeNode(2);
    // root->right = new TreeNode(2);
    // root->left->left = new TreeNode(3);
    // root->left->right = new TreeNode(-2);
    // root->left->left->left = new TreeNode(-1);
    // root->left->left->right = new TreeNode(-1);

    // int maxVal = 0;
    cout << maxPathSum(root) << endl;
    // cout << maxVal << endl;

    return 0;
}
