/*
    Convert a given Binary Tree to Doubly Linked List | Set 1
    https://www.geeksforgeeks.org/in-place-convert-a-given-binary-tree-to-doubly-linked-list/
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

// dll node
struct Node{
    int key;
    Node *next, *prev;

    Node(int x){
        key = x;
        next = prev = nullptr;
    }
};

TreeNode *treeToDll(TreeNode *root, Node *head){
    if(!root)
        return nullptr;

    Node *newNode = new Node(root->key);

    newNode->prev = treeToDll(root->left);
    Node *temp = treeToDll(root->right);
    temp->next = newNode;

    return newNode;
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



    return 0;
}
