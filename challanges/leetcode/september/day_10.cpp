/*
    1022. Sum of Root To Leaf Binary Numbers
*/
#include <bits/stdc++.h>
using namespace std;

// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
public:
    void helper(TreeNode *root, vector<string> &arr, string ans){
        if(root && !root->left && !root->right){
            ans += to_string(root->val);
            arr.push_back(ans);
            // ans = "";
            cout << ans << endl;
            return ;
        }
        if(!root)   return;

        ans += to_string(root->val);
        helper(root->left, arr, ans);
        helper(root->right, arr, ans);
    }

    int sumRootToLeaf(TreeNode* root) {
        vector<string> arr;
        helper(root, arr, "");

        int sum = 0;
        for(auto i:arr){
            sum += stoi(i, 0, 2);
        }

        return sum;
    }
};

int main(){
    // TreeNode *root = new TreeNode(1);
    // root->left = new TreeNode(0);
    // root->right = new TreeNode(1);
    // root->left->left = new TreeNode(0);
    // root->left->right = new TreeNode(1);
    // root->right->left = new TreeNode(0);
    // root->right->right = new TreeNode(1);
    TreeNode *root = new TreeNode(1);
    root->left = new TreeNode(1);

    Solution s;
    cout << s.sumRootToLeaf(root) << endl;

    return 0;
}
