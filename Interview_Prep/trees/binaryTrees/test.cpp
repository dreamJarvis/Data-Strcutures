#include <bits/stdc++.h>
using namespace std;

struct Node{
    int key;
    Node *left, *right;

    Node(int x){
        key = x;
        left = right = nullptr;
    }
};

Node *constructTree(    vector<int> pre, vector<int> post,
                        unordered_map<int, int> &map, int start, int end
){
    static int preIndex = 0;

    if(preIndex > pre.size()-1 || start > end)
        return nullptr;

    Node *currRoot = new Node( pre[preIndex++] );

    if(start == end)    return currRoot;

    int index = map[pre[preIndex]];

    if(index <= end){
        currRoot->left = constructTree(pre, post, map, start, index);
        currRoot->right = constructTree(pre, post, map, index+1, end);
    }

    return currRoot;
}

Node *constructTreeUTIL(vector<int> pre, vector<int> post){
    int n = pre.size();
    unordered_map<int, int> map;

    for(int i = 0; i < n; i++)
        map[post[i]] = i;

    return constructTree(pre, post, map, 0, n-1);
}

void inorderTraversal(Node *root){
    if(!root)   return ;

    inorderTraversal(root->left);
    cout << root->key << " ";
    inorderTraversal(root->right);
}

// Driver function
int main(){
    vector<int> pre({1, 2, 4, 8, 9, 5, 3, 6, 7});
    vector<int> post({8, 9, 4, 5, 2, 6, 7, 3, 1});

    Node *root = constructTreeUTIL(pre, post);

    inorderTraversal(root);

    return 0;
}
