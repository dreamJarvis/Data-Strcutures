/*
    leetcode 404. Sum of Left Leaves
*/
#include <bits/stdc++.h>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

// class Solution {
// public:
//     int sumOfLeftLeaves(TreeNode* root) {
//         if(!root)   return 0;
//         int sum = 0;
//         // string path = "";
//         helper(root, sum);
//
//         // cout << path << endl;
//
//         return sum;
//     }
//
//     void helper(TreeNode *root, int &sum){
//         if(!root)   return;
//         // if(!root->left && !root->right) return ;
//
//         helper(root->left, sum);
//         if(root->left){
//             if(!(root->left)->left && !(root->left)->right)
//                 sum += root->left->val;
//         }
//         helper(root->right, sum);
//     }
// };

class Solution {
    // checks if it's an predecessor to the left leaf
    bool isLeftLeaf(TreeNode* root){
        if( !root )
            return false;
        if( !root->left && !root->right )
            return true;
        return false;
    }

public:
    int sumOfLeftLeaves(TreeNode* root) {
        if( !root ) return 0;

        int sum = 0;
        if(isLeftLeaf(root->left))
            sum = root->left->val;

        return (
            sum + sumOfLeftLeaves(root->left) + sumOfLeftLeaves(root->right)
        );
    }
};

// Driver function
int main(){
    TreeNode *root = new TreeNode(3);
    root->left = new TreeNode(9);
    root->right = new TreeNode(20);
    root->right->left = new TreeNode(15);
    root->right->right = new TreeNode(7);

    // TreeNode *root = new TreeNode(1);
    // root->left = new TreeNode(2);
    // root->right = new TreeNode(3);
    // root->left->left = new TreeNode(4);
    // root->left->right = new TreeNode(5);

    Solution s;
    cout << s.sumOfLeftLeaves(root) << endl;

    return 0;
}
