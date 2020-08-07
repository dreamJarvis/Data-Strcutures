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

void nodesAtKDistance(Node *root, int k, vector<int> &result){
    static int lvl = -1;

    if(!root)   return ;

    lvl++;
    nodesAtKDistance(root->left, k, result);

    cout << root->key << " --- " << lvl << endl;
    if(lvl == k)
        result.push_back(root->key);

    nodesAtKDistance(root->right, k, result);
    lvl--;
}

vector<int> nodesAtKDistanceUtil(Node *root, Node *target, int k, int heightOfTarget){
    vector<int> result;

    // nodesAtKDistance(target, k, result);

    int rightSubstree = abs(k-heightOfTarget);
    cout << rightSubstree << endl;

    Node *temp = root->left;
    nodesAtKDistance(temp, rightSubstree, result);

    return result;
}

int heightOfTarget(Node *root, Node *target){
    if(!root)   return -1;
    if(root == target)  return 0;
    return (
        max(
            heightOfTarget(root->left, target),
            heightOfTarget(root->right, target)
        ) + 1
    );
}

void inorderTraversal(Node *root){
    if(!root)   return;

    inorderTraversal(root->left);
    cout << root->key << " ";
    inorderTraversal(root->right);
}


// Driver function
int main(){
    Node * root = new Node(20);
    root->left = new Node(8);
    root->right = new Node(22);
    root->left->left = new Node(4);
    root->left->right = new Node(12);
    root->left->right->left = new Node(10);
    root->left->right->right = new Node(14);

    // Node *root = new Node(0);
    // root->left = new Node(1);
    // root->right = new Node(3);
    // root->left->right = new Node(2);
    // root->right->right->left = new Node(4);

    Node * target = root->left->right;
    int distance = 2;

    int hot = heightOfTarget(root, target);
    cout << target->key<< " - " << hot << endl;

    for(auto i:nodesAtKDistanceUtil(root, target, distance+1, hot))
        cout << i << " ";
    cout << endl;

    return 0;
}
