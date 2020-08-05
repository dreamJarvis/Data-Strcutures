/*
    Given Inorder and Postorder traversals of a binary tree, print Preorder traversal.
    https://www.geeksforgeeks.org/preorder-from-inorder-and-postorder-traversals/?ref=rp
*/
#include <bits/stdc++.h>
using namespace std;

int preIndex = 5;

// tc : O(n)
// sc : O(n), for using hash-map
void preorder( vector<int> &inorder, vector<int> &postorder,
                unordered_map<int, int> &map, stack<int> &s, int left, int right)
{

}

void preorderUtil(vector<int> &inorder, vector<int> &postorder){
    int n = inorder.size();
    unordered_map<int, int> mp;
    stack<int> s;
}

// Driver function
int main(){
    vector<int> inorder({4, 2, 5, 1, 3, 6});
    vector<int> postorder({4, 5, 2, 6, 3, 1});

    preorderUtil(inorder, postorder);

    return 0;
}
