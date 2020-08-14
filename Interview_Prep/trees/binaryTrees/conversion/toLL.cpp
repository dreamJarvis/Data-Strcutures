/*
    Flatten a binary tree into linked list

    leetcode : https://leetcode.com/problems/flatten-binary-tree-to-linked-list/
    gfg : https://www.geeksforgeeks.org/flatten-a-binary-tree-into-linked-list/
*/
#include <bits/stdc++.h>
using namespace std;

// tree node
struct TreeNode{
    int val;
    TreeNode *left, *right;

    TreeNode(int x){
        val = x;
        left = right = nullptr;
    }
};

void flattenLeftSide(TreeNode *root){
    if(!root)   return;
    static TreeNode *prev = nullptr;
    if(root){
        flattenLeftSide(root->left);
        root->left = prev;
        prev = root;
        flattenLeftSide(root->right);
    }
}

TreeNode *flattenTree(TreeNode *root){
    flattenLeftSide(root);

    while(root && root->right)
        root = root->right;

    TreeNode *pre = nullptr;
    while(root && root->left){
        root->right = prev;
        
    }
}

// void printList(TreeNode *head){
//     while(head){
//         cout << head->val << " ";
//         head = head->left;
//     }
// }

// Driver function
int main(){
    TreeNode *root = new TreeNode(10);
	root->left = new TreeNode(12);
	root->right = new TreeNode(15);
	root->left->left = new TreeNode(25);
	root->left->right = new TreeNode(30);
	root->right->left = new TreeNode(36);

    flattenTree(root);
    // printList(head);

    return 0;
}
