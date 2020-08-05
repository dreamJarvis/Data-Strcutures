// binary tree deletion
/*
    Given a binary tree, delete a node from it by making sure that tree shrinks from the bottom (i.e. the deleted node is replaced by bottom most and rightmost node).
    This different from BST deletion. Here we do not have any order among elements, so we replace with last element.
*/
#include <bits/stdc++.h>
using namespace std;

struct Node {
    int key;
    Node *left, *right;

    Node(int x){
        key = x;
        left = right = nullptr;
    }
};

// using BFS
void insert(Node *root, int data){
    queue<Node *> q;
    q.push(root);

    while(!q.empty()){
        Node *temp = q.front();
        q.pop();

        // if left child is empty
        if(temp->left)
            q.push(temp->left);
        else {
            temp->left = new Node(data);
            break;
        }

        // if right child is empty
        if(temp->right)
            q.push(temp->right);
        else {
            temp->right = new Node(data);
            break;
        }
    }
}

// // to find the k'th element Node in a binary tree
// Node *findKthElement(Node *root, int key){
//     if(!root)   return nullptr;
//
//     if(root->key == key)   return root;
//
//     Node *left = findKthElement(root->left, key);
//     Node *right = findKthElement(root->right, key);
//
//     return (left != nullptr ? left : right);
// }

// find parent node of k'th node element
Node *findParent(Node *root, int key){
    if(!root)   return nullptr;

    if(root->left->key == key || root->right->key == key)
        return root;

    if(findParent(root->left, key) || findParent(root->right, key))
        return root;

    return nullptr;
}

// finding the bottom-most right-most node using recursion
Node *bottomRoghtMost(Node *root){
    if(root->left == nullptr && root->right == nullptr)
        return root;

    if(!root->right)
        return bottomRoghtMost(root->left);
    return bottomRoghtMost(root->right);
}

// // deletion - iteration
// void deletion(Node *root, int key){
//     Node *parent = findParent(root, key);
//
//     Node *lastNode = bottomRoghtMost(root);
//
//     Node *parent2 = findParent(root, lastNode->key);
//
//     cout << "ln: " << lastNode->key << endl;
//     cout << "parent: " << parent->key << endl;
//     cout << "parent2: " << parent2->key << endl;
//
//
//
//     // delete temp2;
// }

// inorder traversal for trees
void inorderTraversal(Node *head){
    if(!head)   return;

    inorderTraversal(head->left);
    cout << head->key << " ";
    inorderTraversal(head->right);
}

// Driver function
int main(){
    vector<int> arr({10, 11, 3, 2, 45, 1, 64});

    Node *btree = new Node(76);     // root node
    for(auto i:arr)
        insert(btree, i);

    inorderTraversal(btree);
    cout << "\n\n";

    // deletion(btree, 11);
    // inorderTraversal(btree);

    cout << findParent(btree, 1)->key << endl;

    return 0;
}
