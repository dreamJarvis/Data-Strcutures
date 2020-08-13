// to find the kth largest element in the tree
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

// right--root--left
void kthLargest(BstNode *root, int &k){
    if(root == nullptr)
        return ;

    kthLargest(root->right, k);

    k--;
    if(k == 0){
        cout << root->data << endl;
    }

    kthLargest(root->left, k);
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

    int k = 2;
    kthLargest(root, k);
    return 0;
}