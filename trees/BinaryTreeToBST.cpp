// To convert a binary tree to a bst
#include <bits/stdc++.h>
using namespace std;

// binary tree node structure
struct Node{
    int data;
    Node *left;
    Node *right;
};

Node *newNode(int data){
    Node *nNode = new Node();
    nNode->data = data;
    nNode->left = nNode->right = nullptr;
    return nNode;
}

// stores inorder traversal of a tree rooted with node
void storeInorder(Node *root, vector<int> &arr){
    // base case
    if(root == nullptr)
        return ;

    // first stores the left subtree
    storeInorder(root->left, arr);

    // copy the root's data
    arr.push_back(root->data);

    // store the right sub-tree
    storeInorder(root->right, arr);
}

// count the nodes in a Binary tree
int countNodes(Node *root){
    if(root == nullptr)
        return 0;
    return countNodes(root->left) + 1 + countNodes(root->right);
}

// copies the content from the array to the binary tree
void arrayToBst(Node *root, vector<int> &arr){
    // base case:
    if(root == nullptr)
        return ;

    // first update the left sub-tree
    arrayToBst(root->left, arr);

    root->data = arr[0];
    arr.erase(arr.begin());

    arrayToBst(root->right, arr);
}

// converts a binary tree to a bst
void binaryTreeToBst(Node *root){
    // base case : tree is empty
    if(root == nullptr)
        return;

    // to count the number of nodes in a binary tree, to create an temporary array
    int n = countNodes(root);

    // create an temp array arr[] and store inorder traversal of tree
    vector<int> arr;
    storeInorder(root, arr);

    // sort the array : to have an inorder , cause inorder of bst is an sorted array, using qsort()
    sort(arr.begin(), arr.end());

    // copy elements back to tree
    arrayToBst(root, arr);
}

void printInorder(Node *root){
    if(root == nullptr)
        return ;

    printInorder(root->left);

    cout << root->data << " ";

    printInorder(root->right);
}

// Driver function
int main(){
    Node *root = nullptr;

    /* Constructing tree given in the above figure
          10
         /  \
        30   15
       /      \
      20       5   */
    root = newNode(10);
    root->left = newNode(30);
    root->right = newNode(15);
    root->left->left = newNode(20);
    root->right->right = newNode(5);

    // convert Binary Tree to BST
    binaryTreeToBst(root);

    cout << "Following is Inorder Traversal of the converted BST:" << endl;
    printInorder (root);

    return 0;
}
