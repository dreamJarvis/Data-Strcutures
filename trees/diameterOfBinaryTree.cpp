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

// // rcursively inserting node in Binary tree
// BTree *insertNode(BTree *root, int data){
//     if(root == nullptr){
//         BTree *newNode = createNode(data);
//         return newNode;
//     }
//
//     if(root->left != nullptr)
//         root->left = insertNode(root->left, data);
//     root->right = insertNode(root->right, data);
//
//     return root;
// }

// traversal
void inorderTraversal(BTree *root){
    if(root == nullptr) return ;

    inorderTraversal(root->left);
    cout << root->val << " ";
    inorderTraversal(root->right);
}

// maxHeight of tree
int height(BTree *root){
    if(root == nullptr) return -1;

    int left = height(root->left) + 1;
    int right = height(root->right) + 1;

    return max(left, right);
}

// diameter of the tree
int diameterOfTree(BTree *root){
    if(root == nullptr)
        return 0;

    int diameterLeft = diameterOfTree(root->left);
    int diameterRight = diameterOfTree(root->right);

    int leftHeight = height(root->left);
    int rightHeight = height(root->right);

    int maxDia = max((leftHeight + rightHeight + 2), max(diameterLeft, diameterRight));
    return maxDia;
}

// Driver function
int main(){
    BTree *root = createNode(1);

    root->left = createNode(2);
    root->right = createNode(3);
    root->left->left = createNode(4);
    root->left->right = createNode(5);

    // inorderTraversal(root);
    // cout << endl;
    //
    // cout << height(root) << endl;

    cout << diameterOfTree(root) << endl;

    return 0;
}
