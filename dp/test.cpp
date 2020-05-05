// Backspace String Compare
#include <bits/stdc++.h>
using namespace std;

struct BTree {
    int val;
    BTree *left, *right;
};

BTree *createNode(int data){
    BTree *newNode = new BTree();
    newNode->val = data;
    newNode->left = newNode->right = nullptr;
    return newNode;
}

// rcursively inserting node in Binary tree
BTree *insertNode(BTree *root, int data){
    if(root == nullptr){
        BTree *newNode = createNode(data);
        return newNode;
    }

    if(root->left != nullptr)
        root->left = insertNode(root->left, data);
    root->right = insertNode(root->right, data);

    return root;
}

void inorderTraversal(BTree *root){
    if(root == nullptr) return ;

    inorderTraversal(root->left);
    cout << root->val << " ";
    inorderTraversal(root->right);
}

// Driver function
int main(){
    BTree *root = nullptr;

    root = insertNode(root, 1);
    root = insertNode(root, 2);
    root = insertNode(root, 3);
    root = insertNode(root, 4);
    root = insertNode(root, 5);

    inorderTraversal(root);

    return 0;
}
