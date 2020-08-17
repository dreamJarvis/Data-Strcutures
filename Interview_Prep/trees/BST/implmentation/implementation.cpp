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

    // inserting accordingly to values
    if(key > root->val)                                 // if val is smaller than root
        root->left = insert(root->left, key);
    else if(key < root->val)                            // if val is larger than root
        root->right = insert(root->right, key);

    return root;                                        // return current value
}

// search for an element in the tree
bool search(TreeNode *root, int k){
    if(!root)   return false;

    if(root->val == k)
        return true;
    else if(k < root->val)
        return search(root->left, k);
    else
        return search(root->right, k);
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
    // TreeNode *root = nullptr;
    // root = insert(root, 50);
    //
    // insert(root, 30);
    // insert(root, 20);
    // insert(root, 40);
    // insert(root, 70);
    // insert(root, 60);
    // insert(root, 80);

    // cout << search(root, 20) << endl;

    // inorderTraversal(root);


    return 0;
}
