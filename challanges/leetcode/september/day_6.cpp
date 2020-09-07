/*
    1305. All Elements in Two Binary Search Trees
*/
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

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
    vector<int> getAllElements(TreeNode* root1, TreeNode* root2) {
        vector<int> arr1, arr2;
        helper(root1, arr1);
        helper(root2, arr2);

        vector<int> result;
        result.reserve(arr1.size() + arr2.size());
        result.insert(result.end(), arr1.begin(), arr1.end());
        result.insert(result.end(), arr2.begin(), arr2.end());

        sort(result.begin(), result.end());
        return result;
    }

    void helper(TreeNode *root, vector<int> &arr){
        if(!root) return ;

        helper(root->left, arr);
        arr.push_back(root->val);
        helper(root->right, arr);

    }
};

int main(){
    TreeNode *root1 = new TreeNode(2);
    root1->left = new TreeNode(1);
    root1->left = new TreeNode(4);

    TreeNode *root2 = new TreeNode(1);
    root2->left = new TreeNode(0);
    root2->right = new TreeNode(3);

    Solution s;
    for(auto i:s.getAllElements(root1, root2))
        cout << i << " ";
    cout << endl;

    return 0;
}
