/*
    Construct Tree from given Inorder and Preorder traversals
    https://www.geeksforgeeks.org/construct-tree-from-given-inorder-and-preorder-traversal/
*/
#include <bits/stdc++.h>
using namespace std;

// node of tree
struct Node {
    char key;
    Node *left, *right;

    Node(int x) {
        key = x;
        left = right = nullptr;
    }
};


Node *constructTree(    string inorder, string preorder,
                        unordered_map<char, int> &map, int start, int end
){
    static int preIndex = 0;

    if(start > end)
        return nullptr;

    Node *newNode = new Node(preorder[preIndex]);
    int index = map[preorder[preIndex++]];

    newNode->left = constructTree(inorder, preorder, map, start, index-1);
    newNode->right = constructTree(inorder, preorder, map, index+1, end);

    return newNode;
}

Node *constructUtil(string inorder, string preorder){
    int n = inorder.size();
    unordered_map<char, int> map;

    for(int i = 0; i < n; i++)
        map[inorder[i]] = i;

    return constructTree(inorder, preorder, map, 0, n-1);
}

void inorderTraversal(Node *head){
    if(!head)   return ;

    inorderTraversal(head->left);
    cout << head->key << " ";
    inorderTraversal(head->right);
}

// Driver function
int main(){
    string inorder = "DBEAFC";
    string preorder = "ABDECF";

    Node *root = constructUtil(inorder, preorder);
    inorderTraversal(root);

    return 0;
}
