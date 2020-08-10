/*
    Print Nodes in Top View of Binary Tree
    https://www.geeksforgeeks.org/print-nodes-top-view-binary-tree/?ref=rp
*/
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

// =============================== Method 1 ================================== //

void leftView(TreeNode *root, int level){
    static int currLvl = 0;
    if(!root) return;

    if(currLvl < level){
        cout << root->val << " ";
        currLvl = level;
    }

    leftView(root->left, level+1);
    leftView(root->right, level+1);
    return;
}

void rightView(TreeNode *root, int level){
    static int currLvl = 0;
    if(!root) return;

    if(currLvl < level){
        cout << root->val << " ";
        currLvl = level;
    }

    rightView(root->right, level+1);
    rightView(root->left, level+1);
    return;
}

// top view
// tc : O(2*log(n))
void topView1(TreeNode *root){
    leftView(root, 1);
    rightView(root->right, 1);
}

// ================================= Method 2 ================================== //
void topView2(TreeNode *root, int level, int h, unordered_map<int, list<Node *>> &map){
    if(!root)   return;

    if(map.count(level)){
        auto i = map[level];
        i.push_back(root);
        map[level] = i;
    }

    topView2(root->left, level+1, h+1, map);
    topView2(root->right, level+1, h-1, map);
    return ;
}

void topViewUtil(TreeNode *root){
    unordered_map<int, list<Node *>> map;
    topView2(root, 0, 0, map);
}

// Driver function
int main(){
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);
    root->right->left = new TreeNode(6);
    root->right->right = new TreeNode(7);
    root->right->right->right = new TreeNode(8);

    // TreeNode *root = new TreeNode(4);
    // root->left = new TreeNode(5);
    // root->right = new TreeNode(2);
    // root->right->left = new TreeNode(3);
    // root->right->right = new TreeNode(1);
    // root->right->left->left = new TreeNode(6);
    // root->right->left->right = new TreeNode(7);

    // topView1(root);
    topView2(root);

    return 0;
}
