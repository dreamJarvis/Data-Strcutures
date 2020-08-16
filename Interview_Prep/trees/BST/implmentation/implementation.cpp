// Binary search tree
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

// insertion in tree
TreeNode *insert(TreeNode *root, int key){
    if(!root)
        return new TreeNode(key);

    if(key > root->val)
        root->left = insert(root->left, key);
    else if(key < root->val)
        root->right = insert(root->right, key);

    return root;
}

// inorder trversal
void inorderTraversal(TreeNode *root){
    if(!root)   return ;

    inorderTraversal(root->left);
    cout << root->val << " ";
    inorderTraversal(root->right);
}

// Driver function
int main(){
    TreeNode *root = nullptr;
    root = insert(root, 50);

    insert(root, 30);
    insert(root, 20);
    insert(root, 40);
    insert(root, 70);
    insert(root, 60);
    insert(root, 80);

    inorderTraversal(root);

    return 0;
}
