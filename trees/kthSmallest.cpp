// Kth smallest and Kth Largest
#include <bits/stdc++.h>
using namespace std;

// binary tree node structure
struct BstNode{
    int data;
    BstNode *left;
    BstNode *right;
};

BstNode *newNode(int data){
    BstNode *nNode = new BstNode();
    nNode->data = data;
    nNode->left = nNode->right = nullptr;
    return nNode;
}

// left--root--right
void kthSmallest(BstNode *root, int &k){
    if(root == nullptr){
        return ;
    }

    kthSmallest(root->left, k);

    k--;
    if(k == 0){
        cout << root->data << endl;
    }

    kthSmallest(root->right, k);
}

// Driver fucntion
int main(){
    BstNode *root = nullptr;
    root = newNode(15);
    root->left = newNode(10);
    root->right = newNode(25);
    root->left->left = newNode(8);
    root->left->right = newNode(11);
    root->left->left->right = newNode(9);
    root->right->left = newNode(24);
    root->right->right = newNode(34);

    int k = 4;
    kthSmallest(root, k);
    return 0;
}
