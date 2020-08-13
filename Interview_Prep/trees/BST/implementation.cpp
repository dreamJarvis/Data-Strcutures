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

void insert(TreeNode *root, int key){
    if(!root)   return;

    if(val > root->val)
        root->left = new TreeNode(key);
}

// Driver function
int main(){

    return 0;
}
